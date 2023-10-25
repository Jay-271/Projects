//Jason Avila-Soria
//Ethan Spivey
//Marquis Fowler
//Ricardo Zeferino-Rodriguez
//Colton Turner
//Michael Khang Trinh

// This program allows display and editing of text art (also called ASCII art).

#include <iostream>
#include <fstream>
#include <cctype>
#include <windows.h>
#include <conio.h>
#include "Definitions.h"
using namespace std;

const int MAXPOSITIONS = MAXROWS * MAXCOLS;

void Clear() {
	gotoxy(MAXROWS + 1, 0);
	for (int i = 1; i < 5; i++)
	{
		clearLine(MAXROWS + i, 100);
	}
	gotoxy(MAXROWS + 1, 0);
}
void Clear(int lines) {
	gotoxy(MAXROWS + 1, 0);
	for (int i = 1; i < lines; i++)
	{
		clearLine(MAXROWS + i, 100);
	}
	gotoxy(MAXROWS + 1, 0);
}
int main()
{
	//initial canvases needed + 
	char canvas[MAXROWS][MAXCOLS];
	char oldCanvas[MAXROWS][MAXCOLS];
	char currentReplace, newReplace;
	char choice = 'S';
	int moveCol, moveRow;
	bool animate = false;

	initCanvas(canvas);
	initCanvas(oldCanvas);

	do 
	{
		//after every instance of a choice then display the new canvas and move to menu 
		displayCanvas(canvas);
		gotoxy(MAXROWS + 1, 0);
		printf("<E>dit / <M>ove / <R>eplace / <D>raw / <C>lear / <U>ndo / <L>oad / <S>ave / <Q>uit: ");

		// Read a single character from the input but make sure if it is an enter key dont move to the next line
		do 
		{
			cin.get(choice);
			if (choice == '\n')
			{
				gotoxy(23, 84);
			}

		} while (choice == '\n');

		cout << endl;
		//move canvas option
		if (choice == 'M' || choice == 'm') 
		{
			Clear(2);
			//clear line then print 
			cout << "Enter column units to move: ";
			cin >> moveCol;
			cout << "Enter row units to move: ";
			cin >> moveRow;
			copyCanvas(oldCanvas, canvas);
			moveCanvas(canvas, moveRow, moveCol);
			//clear line to see main menu again:
			Clear();
		}
		else if (choice == 'E' || choice == 'e') 
		{
			Clear(2);
			cout << "Press <Esc> to stop editing.";
			copyCanvas(oldCanvas, canvas);
			editCanvas(canvas);
			Clear(2);
		}
		//all these ignores take care of any enter keys in the buffer so that the cin.get works 100% of the time
		else if (choice == 'R' || choice == 'r') 
		{
			cin.ignore();
			Clear();
			cout << "Enter character to replace: ";
			cin.get(currentReplace);
			cin.ignore();
			cout << "Enter character to replace with: ";
			cin.get(newReplace);
			cin.ignore();
			copyCanvas(oldCanvas, canvas);
			replace(canvas, currentReplace, newReplace);
			Clear();
		}
		else if (choice == 'U' || choice == 'u') 
		{
			copyCanvas(canvas, oldCanvas);
			Clear();
		}
		else if (choice == 'L' || choice == 'l') 
		{
			copyCanvas(canvas, oldCanvas);
			initCanvas(canvas);
			loadCanvas(canvas);
		}
		else if (choice == 'S' || choice == 's') 
		{
			saveCanvas(canvas);
		}
		else if (choice == 'C' || choice == 'c') {
			copyCanvas(oldCanvas, canvas);
			initCanvas(canvas);
		}
		else if (choice == 'D' || choice == 'd') {
			Clear(2);
			copyCanvas(oldCanvas, canvas);
			menuTwo(canvas, oldCanvas, animate, choice);

		}

		//while loop to cycle through untill the user hits the Quit key
	} while (choice != 'q' && choice != 'Q');

	return 0;
}

//use to move when editing
void gotoxy(short row, short col)
{
	COORD pos = { col, row };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void clearLine(int lineNum, int numOfChars)
{
	// Move cursor to the beginning of the specified line on the console
	gotoxy(lineNum, 0);

	// Write a specified number of spaces to overwrite characters
	for (int x = 0; x < numOfChars; x++)
		cout << " ";

	// Move cursor back to the beginning of the line
	gotoxy(lineNum, 0);
}


void replace(char canvas[][MAXCOLS], char oldCh, char newCh)
{
	//for loop cycles through whole array and finds old char to replace w/ new char
	for (int i = 0; i < MAXROWS; i++)
	 {
		for (int x = 0; x < MAXCOLS; x++)
		{
			if (canvas[i][x] == oldCh) 
			{
				canvas[i][x] = newCh;
			}
		}
	}
}


void editCanvas(char canvas[][MAXCOLS])
{
	char input;
	int row = 0, col = 0;

	// Move cursor to beginning 
	gotoxy(row, col);

	do 
	{
		// get a single character from the keyboard
		input = _getch();

		//takes care of any special cases
		if (input == SPECIAL) 
		{
			input = _getch();

			if (input == UPARROW && row - 1 >= 0) 
			{
				row--;
				gotoxy(row, col);
			}
			else if (input == DOWNARROW && row + 1 < MAXROWS) 
			{
				row++;
				gotoxy(row, col);
			}
			else if (input == LEFTARROW && col - 1 >= 0) 
			{
				col--;
				gotoxy(row, col);
			}
			else if (input == RIGHTARROW && col + 1 < MAXCOLS) 
			{
				col++;
				gotoxy(row, col);
			}

		}
		//takes care of any ASCII characters that are typable
		else if (input >= 32 && input <= 126 && input != ESC) 
		{
			canvas[row][col] = input;
			cout << input;
			gotoxy(row, col);
		}
		//takes care of any f1-f9 keys by geting the rest of the code from it but not doing anything with it
		else if (input == '\0') 
		{
			input = _getch();

		}

	} while (input != ESC);

	// >>> bottom is notes for general idea <<<<

	//add if _getch( = SPECIAL then get another input to see which arrow key
		//take into account only those values, f1 and such should not be inputted
}


void moveCanvas(char canvas[][MAXCOLS], int rowValue, int colValue)
{
	// TODO: write code for the function

	//use a temp second array (cpy to second array the original then replace original after transform)
	char tempCanvas[MAXROWS][MAXCOLS];
	int newRow, newCol;

	initCanvas(tempCanvas);

	//iterates through full array length
	for (int i = 0; i < MAXROWS; i++) 
	{
		for (int x = 0; x < MAXCOLS; x++) 
		{
			//sets a new col and row variable to row/col values that were entered 
				//then adds +1col or +1 row as it goes through the loop
			newRow = rowValue + i;
			newCol = colValue + x;

			// checks if new row and new col are WHITIN the bounds of the array and ONLY if then it copies files from the canvas to the temp canvas
				//this essentially "saves" the moved canvas
			if (newRow >= 0 && newRow < MAXROWS && newCol >= 0 && newCol < MAXCOLS)
				tempCanvas[newRow][newCol] = canvas[i][x];

		}
	}

	//for loop to replacae any NON printable ASCII values to a space (filling in the canvas
	for (int i = 0; i < MAXROWS; i++) 
	{
		for (int x = 0; x < MAXCOLS; x++) 
		{
			if (tempCanvas[i][x] < 32 || tempCanvas[i][x] > 126) 
			{
				tempCanvas[i][x] = ' ';
			}
			//the above makes sure the items in the canvas are printed in the correct locations from the tempcanvas
			canvas[i][x] = tempCanvas[i][x];
		}
	}

}


void initCanvas(char canvas[][MAXCOLS])
{
	//Initializes every position in array to space characters
	for (int i = 0; i < MAXPOSITIONS; i++)
	{
		canvas[0][i] = ' ';
	}
}


void displayCanvas(char canvas[][MAXCOLS])
{
	// Clear the screen
	system("cls");

	// TODO: write code for the function

	//Displays every canavs position with border limits around  it for correct formatting
	for (int i = 0; i < MAXROWS; i++) 
	{
		for (int x = 0; x < MAXCOLS; x++) 
		{
			cout << canvas[i][x];
		}
		cout << '|' << endl;
	}
	//prints bottom of the canvas line
	for (int i = 0; i < MAXCOLS; i++)
		cout << "-";

}


void copyCanvas(char to[][MAXCOLS], char from[][MAXCOLS])
{
	//Copies the canavs so it can be used for the undo task
	for (int i = 0; i < MAXROWS; i++) 
	{
		for (int x = 0; x < MAXCOLS; x++) 
		{
			to[i][x] = from[i][x];
		}
	}
}


void saveCanvas(char canvas[][MAXCOLS])
{
	char fileName[FILENAMESIZE - 12];
	char final[FILENAMESIZE];
	int row = 0, col = 0;

	Clear(2);
	cin.ignore();

	//Gets the name of the filename from the user 
	cout << "Enter the filename (don't enter 'txt'): ";
	cin.getline(fileName, FILENAMESIZE - 12);

	snprintf(final, FILENAMESIZE, "%s%s%s", "SavedFiles\\", fileName, ".txt");



	ofstream outFile;
	outFile.open(final);

	if (!outFile)
		// Displays if a file cannot be saved 
	{
		cerr << "ERROR: File cannot be saved.\n";
		system("pause");
		return;
	}

	//Writes everything to the file including and gives a message to let you know it has been saved
	for (int i = 0; i < MAXROWS; i++) 
	{
		for (int x = 0; x < MAXCOLS; x++) 
		{
			outFile << canvas[i][x];
		}
		outFile << endl;
	}

	outFile.close();
	gotoxy(0, 0);
	Clear(2);

	cout << "File saved!\n";
	system("pause");
}


void loadCanvas(char canvas[][MAXCOLS])
{
	// TODO: write code for the function
	char fileName[FILENAMESIZE - 12];
	char final[FILENAMESIZE];
	char c;
	int row = 0, col = 0;

	Clear(2);
	cin.ignore();

	// Ask for file name, also gives parameters 
	cout << "Enter the filename (don't enter 'txt'): ";
	cin.getline(fileName, FILENAMESIZE - 12);

	snprintf(final, FILENAMESIZE, "%s%s%s", "SavedFiles\\", fileName, ".txt");

	ifstream inFile;
	inFile.open(final);

	//get file name from user ^
	if (!inFile) 
	{
		cerr << "ERROR: File cannot be read.\n";
		system("pause");
		return;
	}

	while (inFile.get(c) && row < MAXROWS) 
	{
		if (c == '\n') 
		{
			row++;
			col = 0;
		}

		else if (row < MAXROWS && col < MAXCOLS && c != '\n') 
		{
			canvas[row][col] = c;
			col++;
			if (col >= MAXCOLS) {
				//dont read to array 
				while (inFile.get(c) && c != '\n') 
				{
					//keeps reading untill newline is found.

				}
				col = 0;
				row++;
				//as long as col is less than the MAX columns then print the items of the file
				//else if the col from where its reading from is bigger than MAX cols then dont read *** to array *** , instead read but dont input to array
				// do the following until reaching an endline
			}

		}
	}

	inFile.close();

}