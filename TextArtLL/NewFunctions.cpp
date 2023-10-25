#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Definitions.h"
using namespace std;


Point::Point(DrawPoint p)
{
	row = (int)round(p.row);
	col = (int)round(p.col);
}

// https://math.stackexchange.com/questions/39390/determining-end-coordinates-of-line-with-the-specified-length-and-angle
DrawPoint findEndPoint(DrawPoint start, int len, int angle)
{
	DrawPoint end;
	end.col = start.col + len * cos(degree2radian(angle));
	end.row = start.row + len * sin(degree2radian(angle));
	return end;
}


// Use this to draw characters into the canvas, with the option of performing animation
void drawHelper(char canvas[][MAXCOLS], Point p, char ch, bool animate)
{
	// Pause time between steps (in milliseconds)
	const int TIME = 50;

	// Make sure point is within bounds
	if (p.row >= 0 && p.row < MAXROWS && p.col >= 0 && p.col < MAXCOLS)
	{
		// Draw character into the canvas
		canvas[p.row][p.col] = ch;

		// If animation is enabled, draw to screen at same time
		if (animate)
		{
			gotoxy(p.row, p.col);
			printf("%c", ch);
			Sleep(TIME);
		}
	}
}


// Fills gaps in a row caused by mismatch between match calculations and screen coordinates
// (i.e. the resolution of our 'canvas' isn't very good)
void drawLineFillRow(char canvas[][MAXCOLS], int col, int startRow, int endRow, char ch, bool animate)
{
	// determine if we're counting up or down
	if (startRow <= endRow)
		for (int r = startRow; r <= endRow; r++)
		{
			Point point(r, col);
			drawHelper(canvas, point, ch, animate);
		}
	else
		for (int r = startRow; r >= endRow; r--)
		{
			Point point(r, col);
			drawHelper(canvas, point, ch, animate);
		}
}


// Draw a single line from start point to end point
void drawLine(char canvas[][MAXCOLS], DrawPoint start, DrawPoint end, bool animate)
{
	char ch;

	Point scrStart(start);
	Point scrEnd(end);

	// vertical line
	if (scrStart.col == scrEnd.col)
	{
		ch = '|';

		drawLineFillRow(canvas, scrStart.col, scrStart.row, scrEnd.row, ch, animate);
	}
	// non-vertical line
	else
	{
		int row = -1, prevRow;

		// determine the slope of the line
		double slope = (start.row - end.row) / (start.col - end.col);

		// choose appropriate characters based on 'steepness' and direction of slope
		if (slope > 1.8)  ch = '|';
		else if (slope > 0.08)  ch = '`';
		else if (slope > -0.08)  ch = '-';
		else if (slope > -1.8) ch = '\'';
		else ch = '|';

		// determine if columns are counting up or down
		if (scrStart.col <= scrEnd.col)
		{
			// for each column from start to end, calculate row values
			for (int col = scrStart.col; col <= scrEnd.col; col++)
			{
				prevRow = row;
				row = (int)round(slope * (col - start.col) + start.row);

				// draw from previous row to current row (to fill in row gaps)
				if (prevRow > -1)
				{
					drawLineFillRow(canvas, col, prevRow, row, ch, animate);
				}
			}
		}
		else
		{
			// for each column from start to end, calculate row values
			for (int col = scrStart.col; col >= scrEnd.col; col--)
			{
				prevRow = row;
				row = (int)round(slope * (col - start.col) + start.row);

				// draw from previous row to current row (to fill in row gaps)
				if (prevRow > -1)
				{
					drawLineFillRow(canvas, col, prevRow, row, ch, animate);
				}
			}
		}
	}
}


// Draws a single box around a center point
void drawBox(char canvas[][MAXCOLS], Point center, int height, bool animate)
{
	int sizeHalf = height / 2;
	int ratio = (int)round(MAXCOLS / (double)MAXROWS * sizeHalf);

	// Calculate where the four corners of the box should be
	DrawPoint points[4];
	points[0] = DrawPoint(center.row - sizeHalf, center.col - ratio);
	points[1] = DrawPoint(center.row - sizeHalf, center.col + ratio);
	points[2] = DrawPoint(center.row + sizeHalf, center.col + ratio);
	points[3] = DrawPoint(center.row + sizeHalf, center.col - ratio);

	// Draw the four lines of the box
	for (int x = 0; x < 3; x++)
	{
		drawLine(canvas, points[x], points[x + 1], animate);
	}
	drawLine(canvas, points[3], points[0], animate);

	// Replace the corners with a better looking character
	for (int x = 0; x < 4; x++)
	{
		drawHelper(canvas, points[x], '+', animate);
	}
}


// Menu for the drawing tools
void menuTwo(Node*& current, List& undoList, List& redoList, List& clips, bool& animate)
{
	char choice = 'D';
	Point pos1, pos2;
	DrawPoint tree;
	char input, condition;
	int row = 0, col = 0, height = 0, branchAngle, startAngle = 270;

	Node* cpy = NULL;

	do {
		//this is so it doesnt refresh the canvas every time the user switches between animating and not animating

		if (choice != 'A' && choice != 'D')
			displayCanvas(current->item);
		gotoxy(MAXROWS + 1, 0);
		if (animate)
		{
			if (redoList.count == 0)
			{
				printf("<A>nimate: Y / <U>ndo: %d / Cl<I>p: %d", undoList.count, clips.count);
			}
			else
			{
				printf("<A>nimate: Y / <U>ndo: %d / Red<O>: %d / Cl<I>p: %d", undoList.count, redoList.count, clips.count);
			}
			if (clips.count >= 2)

			{
				printf(" / <P>lay ");
			}
		}
		else
		{
			if (redoList.count == 0)
			{
				printf("<A>nimate: N / <U>ndo: %d / Cl<I>p: %d", undoList.count, clips.count);
			}
			else
			{
				printf("<A>nimate: N / <U>ndo: %d / Red<O>: %d / Cl<I>p: %d", undoList.count, redoList.count, clips.count);
			}
			if (clips.count >= 2)
			{
				printf(" / <P>lay ");
			}
		}
		cout << endl;
		printf("<F>ill / <L>ine / <B>ox / <N>ested Boxes / <T>ree / <M>ain Menu: ");


		// Read a single character from the input but make sure if it is an enter key dont move to the next line
		do
		{
			cin.get(choice);
			if (choice == '\n')
			{
				gotoxy(MAXROWS + 2, 65);
			}

		} while (choice == '\n');

		cout << endl;
		choice = toupper(choice);
		// If user clicks 'A' or 'a' the animate function will turn off or on.
		if (choice == 'A') 
		{
			if (animate)
				animate = false;
			else if (!animate)
				animate = true;
			clear(3);
		}
		// If user clicks 'F' or 'f' the fill menu opens
		else if (choice == 'F') 
		{
			clear(3);
			// Moves cursor to user's preferred position
			gotoxy(MAXROWS + 1, 0);
			//Asks user to input character to fill at position of cursor or to press the ESC key to cancel the fill operation
			printf("Enter character to fill with from current location / <ESC> to cancel");
			//initilize input, row, col

			input = getPoint(pos1);
			if (input != ESC)
			{
				addUndoState(undoList, redoList, current);

				fillRecursive(current->item, pos1.row, pos1.col, current->item[pos1.row][pos2.row], input, animate);
			}

		}
		else if (choice == 'L') 
		{
			clear(3);
			
			//Choose starting and ending point
			printf("Type any letter to choose start point / <ESC> to cancel");
			condition = getPoint(pos1);
			clear(3);
			if (condition != ESC) {
				printf("Type any letter to choose end point / <ESC> to cancel");
				condition = getPoint(pos2);
			}
			if (condition != ESC)
			{
				addUndoState(undoList, redoList, current);
				drawLine(current->item, pos1, pos2, animate);
			}

			clear(3);

		}
		else if (choice == 'B') 
		{
			clear(3);
			
			//Get box size from the user
			printf("Enter box height: ");
			cin >> height;
			cin.ignore();

			clear(3);

			printf("Type any letter to choose box center, or <C> for screen center / <ESC> to cancel");
			condition = getPoint(pos1);

			condition = toupper(condition);
			if (condition == 'C') 
			{
				pos1 = Point(MAXROWS /2, MAXCOLS / 2);
			}
			// only executes when the user enters a valid input above, otherwise if they chose ESC it doesnt draw a box
			if (condition != ESC) {
				addUndoState(undoList, redoList, current);
				drawBox(current->item, pos1, height, animate);
			}
			clear(3);
		}
		else if (choice == 'N')
		{
			clear(3);
			
			//Get box size from the user
			printf("Enter size of largest box: ");
			cin >> height;
			cin.ignore();
			clear(3);

			// Get center position by having user enter a letter or pressing 'C' or 'c' to center the middle of screen or to press ESC to cancel operation.
			printf("Type any letter to choose box center, or <C> for screen center / <ESC> to cancel");
			condition = getPoint(pos1);
			
			condition = toupper(condition);
			//Position if user chooses the center of the screen
			if (condition == 'C') 
			{
				pos1 = Point(MAXROWS /2 , MAXCOLS / 2);
			}

			if (condition != ESC) {
				addUndoState(undoList, redoList, current);
				drawBoxesRecursive(current->item, pos1, height, animate);
			}
			clear(3);
		}
		else if (choice == 'T') 
		{
			clear(3);

			//Get height from the user
			printf("Enter approximate tree height: ");
			cin >> height;
			cin.ignore();
			clear(3);

			// Get branch angle value from user.
			printf("Enter branch angle: ");
			cin >> branchAngle;
			cin.ignore();
			clear(3);

			// Get center position by having user enter a letter or pressing 'C' or 'c' to center the middle of screen or to press ESC to cancel operation.
			printf("Type any letter to choose tree center, or <C> for screen center / <ESC> to cancel");
			condition = getPoint(pos1);

			tree = DrawPoint(pos1);

			condition = toupper(condition);
			//calculates and sets the position of the tree center to the bottom middle of the canvas
			if (condition == 'C') 
			{
				tree = DrawPoint(MAXROWS -1, MAXCOLS /2);
			}
			// only executes when the user enters a valid input above, otherwise if they chose ESC it doesnt draw a tree

			if (condition != ESC) 
			{
				addUndoState(undoList, redoList, current);
				treeRecursive(current->item, tree, height, startAngle, branchAngle, animate);
			}
			clear(3);
		}
		else if (choice == 'U')
		{
			restore(undoList, redoList, current);
			clear();
		}
		else if (choice == 'O')
		{
			restore(redoList, undoList, current);
		}
		else if (choice == 'I')
		{
			cpy = newCanvas(current);
			addNode(clips, cpy);
		}
		else if (choice == 'P' && clips.count >= 2)
		{
			play(clips);
		}
		clear(3);
	} while (choice != 'M' && choice != 'm');
}


// Get a single point from screen, with character entered at that point
char getPoint(Point& pt)
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
			cout << input;
			pt.col = col;
			pt.row = row;

			return input;
		}
		//takes care of any f1-f9 keys by geting the rest of the code from it but not doing anything with it
		else if (input == '\0')
		{
			input = _getch();

		}
		
	} while (input != ESC);

	return ESC;
}


// Recursively fill a section of the screen
void fillRecursive(char canvas[][MAXCOLS], int row, int col, char oldCh, char newCh, bool animate)
{
	Point temp = Point(row, col);
	
	// base case check if the current position is outside the bounds

	if (row < 0 || row >= MAXROWS || col < 0 || col >= MAXCOLS)
	{
		return;
	}

	// base case 2 check if the current position is not the old character
	if (canvas[row][col] != oldCh || oldCh == newCh)
	{
		return;
	}

	//so only if it is whithin bounds and it is an oldch then it should do the recursive calls:
	//drawLineFillRow(canvas, col, row, row, newCh, animate);
	drawHelper(canvas, temp, newCh, animate);

	fillRecursive(canvas, row - 1, col, oldCh, newCh, animate);
	fillRecursive(canvas, row + 1, col, oldCh, newCh, animate);
	fillRecursive(canvas, row, col - 1, oldCh, newCh, animate);
	fillRecursive(canvas, row, col + 1, oldCh, newCh, animate);
}


// Recursively draw a tree
void treeRecursive(char canvas[][MAXCOLS], DrawPoint start, int height, int startAngle, int branchAngle, bool animate)
{
	//base case: bounds of array
	if (height <= 2 || start.row < 0 || start.row >= MAXROWS || start.col < 0 || start.col >= MAXCOLS) 
	{
		return;
	}

	DrawPoint end = findEndPoint(start, height / 3, startAngle);
	//this is here to make it look like it starts drawing from the trunk

	drawLine(canvas, start, end, animate);
	treeRecursive(canvas, end, height - 2, startAngle + branchAngle, branchAngle, animate);
	treeRecursive(canvas, end, height - 2, startAngle - branchAngle, branchAngle, animate);
	
	//this is to overwrite some | characters that are wrong (supposed to be ` or ')
	//i dont know why this happens 
	// nevermind, figured it out. here's a memento
	//	drawLine(canvas, start, end, animate);

}


// Recursively draw nested boxes
void drawBoxesRecursive(char canvas[][MAXCOLS], Point center, int height, bool animate)
{
	//base case: bounds of array
	if (center.row < 0 || center.row >= MAXROWS || center.col < 0 || center.col >= MAXCOLS)
	{
		return;
	}
	// impossible to draw smaller boxes:
	if (height < 2) {
		return;
	}
	drawBox(canvas, center, height, animate);
	drawBoxesRecursive(canvas, center, height - 2, animate);
}