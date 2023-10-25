//scanf and printf vvv with only C
/*
scanf/printf stuff

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//stopping value for loop
const int SENT = 0;

int main()
{
	int value, total;
	
	printf("This program adds a list of numbers.\n");
	printf("Use %d to signal the end of the list.\n", SENT);

	total = 0;

	do
	{
		printf(" ? ");
		if (scanf("%d", &value) != 1)
		{
			printf("Error reading input");
			return 1;
		}

		if (value != SENT)
		{
			total += value;
		}
	} while (value != SENT);

	printf("The total is: %d\n", total);

	return 0;
}
*/

//Arrays Example 
/*
#include <iostream>
using namespace std;

const int MAXSTUDENTS = 50;

int main()
{
	int grades[MAXSTUDENTS]; // array to hold student grades
	int total = 0; // sum of grades
	double avg; // average grade
	int studentCount; //number of actual students

	printf("How many students? ");
	cin >> studentCount;
	
	// error condition loop (doesnt go above array size)
	while (studentCount > MAXSTUDENTS)
	{
		printf("ERROR: Your student amount is greater than the limit (%d students)\n", MAXSTUDENTS);
		printf("Please enter another value for students: ");
		cin >> studentCount;
	}

	//loop to get grades and store in array
	for (int count = 0; count < studentCount; count++)
	{
		printf("Enter grade for student #%d: ", (count + 1));
		cin >> grades[count];
	}

	// this gets the average grade
	for (int count = 0; count < studentCount; count++)
	{
		total += grades[count];
	}
	avg = total / (double)studentCount;
	cout << endl;

	printf("The average score for the class is: %.2f\n", avg);

	return 0;
}
*/

//enumrate stuff
/*
#include <iostream>
using namespace std;

int main()
{
	enum class Coin {penny = 1, nickel = 5, dime = 10, quarter = 25};
	
	Coin deposit;
	
	deposit = Coin::nickel;

	switch (deposit)
	{
		case Coin::penny:
			printf("you deposited a %d cents", Coin::penny);
			break;
		case Coin::nickel:
			printf("you deposited a %d cents", Coin::nickel);
			break;
		case Coin::dime:
			printf("you deposited a %d cents", Coin::dime);
			break;
		case Coin::quarter:
			printf("you deposited a %d cents", Coin::quarter);
			break;

	}

}
*/

//typdef stuff
/*
#include <iostream>
using namespace std;

typedef char* Ptr;

void Swap(char* a, char* b)
{
	char swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int main()
{
	char ch = 'J';
	char ss = 'L';
	Ptr CharacterPointer = &ch; // stores the POINTER//DATA LOCATION value

	*CharacterPointer = 'M'; // changes J to M through directly accessing that memory data

	cout << ch << endl;
	cout << ss << endl;

	Swap(CharacterPointer, &ss);
	cout << "after switch\n" << endl;

	cout << ch << endl;
	cout << ss << endl;

	return 0;
}

// basically *a are pointer variables but couldve fixed swap function w/ reference variables by doing int& a
// THE DIFFERENCE IN USING EITHER OR HAS TO DO W/ COMPILER!!! --> you can CHOOOSE to move pointer to point to sum else w/ the *a but NOT with the reference variable

*/

//array stuff but calling it into functions (also started to use .H header files
/*
#include <iostream>
#include "Functions.h" // calls the header file which has the array swap function I made
using namespace std;

// constant variable to set the size of the array
const int MAXSIZE = 3;

// function to swap the elements of an array
void swapArray(int myArray[], const int SIZE);

int main()
{
	// initialize an array with the values 1, 2, 3
	int nums[MAXSIZE] = { 1, 2, 3 };

	// print the original array
	cout << "Before swap:" << endl;
	for (int i = 0; i < MAXSIZE; i++) {
		printf("Array index %d is %d\n", i, nums[i]);
	}

	// call the swap function
	swapArray(nums, MAXSIZE);

	// print the array after the swap
	cout << "After swap:" << endl;
	for (int i = 0; i < MAXSIZE; i++) {
		printf("Array index %d is %d\n", i, nums[i]);
	}

	return 0;
}
*/

// "C-style" string (important)
/*#include <iostream>
#include "Functions.h" // calls the header file which has the array swap function I made
#include <cstring> //*****************NEEEEEEEEEEEEEEEEEEDDDDDDDDDD*****************
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//have to have "\0" to end

const int MAXSIZE = 100;
void arrayCopy(char Destination[], const char Source[], const int destSize);

bool validateInt(const char buf[], const int MAXSIZE);

int main()
{
	char x[MAXSIZE], a[MAXSIZE];

	arrayCopy(x, "L Bozo", MAXSIZE);
	// do not use strcpy since no maxsize
	// CAN use this but snprintf PREFFERED!!!!!!!
		//strncpy(x, "Bozo L", MAXSIZE);

	snprintf(x, MAXSIZE, "Bozo %c", 'L');
	//^^ "Prints" to the array "x" and replaces it from 0

	
	size_t size = strlen(x);

	snprintf(x + size, MAXSIZE - size, " Get Good");
	//^^This will find the ending of previous string and ADD ONTO IT where the previous ended 
		//first need to find \0

	printf(x);

	int someShi, some;

	cout << "\nEnter an INT: ";
	cin >> some;
	// THIS leaves the \n (enter key)in the buffer!
	cin.ignore();// get rid of the enter key 
		//--> (if user types "\n" its read as two ASCII not as one char so would be incorrect data type)

	printf("\nEnter some words: ");
	
	// to get array strings DONT use cin >> a; 
		//-->use:
	cin.getline(a, MAXSIZE);



	cout << "\nEnter an INT: ";
	cin >> someShi;

	//if ERROR STATE:

	while (cin.fail()) // checks for error
	{
		// WRONG type of data clear
		cin.clear();
		// to whipe keyboard buffer:
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//--> ignores next ONE character, can put an integer to ignore (x) amount of characters OR that stuff in the function rn which states:
			//ignore max OR up to '\n' (enter)
		cout << "Enter a correct variable: ";
		cin >> someShi;
	}
	cin.ignore();// get rid of the enter key

	printf("\nYou entered the INT: %d %s and the INT: %d\n", some, a, someShi);

	//*****************OPTION 2 for getting INT from a string**************
	char buffer[MAXSIZE];
	int y;

	cout << "\nEnter an INT: ";
	cin.getline(buffer, MAXSIZE);

	//to check if string is ONLY digits
	while (!validateInt(buffer, MAXSIZE))
	{
		cout << "\nERROR not an INT\n";
		cout << "\nEnter an INT: ";
		cin.getline(buffer, MAXSIZE);
	}


	y = atoi(buffer); //converts string to INT
	cout << "converted int = " << y;
	return 0;
}

void arrayCopy(char Destination[], const char Source[], const int destSize)
{
	int i;
	int stopValue = destSize - 1;

	for (i = 0; i < stopValue && Source[i] != '\0'; i++)
	{
		Destination[i] = Source[i];
	}
	Destination[i] = '\0';

}

bool validateInt(const char buf[], const int MAXSIZE)
{
	for (int i = 0; buf[i] != '\0'; i++)
	{
		if (!isdigit(buf[i]))
			return false;
	}

	return true;
}
*/

//STRUCTURES :)))
/*
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

const int MAXNAMESIZE = 6;
const int MAXSTUDENTS = 50;

struct Date {
	int month;
	int day;
	int year;
};

struct Student {
	char name[MAXNAMESIZE]; // 6 bytes
	double gpa; // 8 bytes
	int hours; // 4 bytes
	Date birthdate;
};

void printStudent(const Student &stu);
void initStudent(Student& stu, const char nm[], const double gpa, int hr, const Date& bd);

int main()
{
	//structure pointer
	Student john;
	Student* johnPtr = &john;

	(*johnPtr).gpa = 3.7;
	//this vvv does this ^^^. only works for structure pointers.
	johnPtr->gpa = 3.7;

	Student stuList[MAXSTUDENTS];
	Date bd;

	bd.month = 3;
	bd.day = 12;
	bd.year = 2001;

	initStudent(stuList[0], "John", 3.7, 46, bd);

	bd.month = 11;
	bd.day = 8;
	bd.year = 2002;
	initStudent(stuList[1], "Becky", 3.9, 24, bd);

	// stuList[1].name[3] = 'c'; (navigate Structures)

	for (int x = 0; x < 2; x++)
	{
		cout << "Student #: " << x << endl;
		printStudent(stuList[x]);
		cout << endl;
	}


	return 0;
}

void printStudent(const Student &stu)
{

	cout << stu.name << endl << stu.gpa << endl << stu.hours << endl;
	cout << "Birthday: ";
	cout << stu.birthdate.year << '/' << stu.birthdate.month << '/' << stu.birthdate.day << endl;
}
void initStudent(Student& stu, const char nm[], const double gpa, int hr, const Date& bd)
{
	stu.gpa = gpa;
	stu.hours = hr;
	snprintf(stu.name, sizeof(stu.name), nm);
	stu.birthdate = bd;
	//or instead of MAXNAMESIZE can do sizeof(john.name)
}
*/
// Program to demonstrate the use of a struct to draw a square on the screen
// (or a 3D cube if the commented section of code is uncommented)
// This code is tested and works on Visual Studio for Windows
// and has been tested and works on some newer Unix/Linux environments.
// It is not guaranteed to work on other machines
// Reference: https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
/*
#include <iostream>
using namespace std;

// Control Sequence Introducer
#define CSI "\x1b["

struct Point
{
	int row, col;
};

// Pack up rowValue and colValue into a Point struct
Point setPoint(int rowValue, int colValue);

// Draw a line (using asterisks) between the two Points
void drawLine(Point start, Point end);

// Clear the screen
inline void clearScr();

// Move cursor to a specific row,col on screen; 1,1 = top left corner
inline void moveCursor(int row, int col);

int main()
{
	clearScr();

	// array to hold points in a square
	Point figure[8];

	// Store the points
	figure[0] = setPoint(5, 10);
	figure[1] = setPoint(5, 20);
	figure[2] = setPoint(11, 20);
	figure[3] = setPoint(11, 10);

	// Draw lines between the points
	drawLine(figure[0], figure[1]);
	drawLine(figure[1], figure[2]);
	drawLine(figure[2], figure[3]);
	drawLine(figure[0], figure[3]);



	 // <--- Get rid of this comment if you want to see the a cube

	// Add extra points for a 3D cube
	figure[4] = setPoint(2, 15);
	figure[5] = setPoint(2, 25);
	figure[6] = setPoint(8, 25);
	figure[7] = setPoint(8, 15);

	// Draw the extra lines for the cube
	drawLine(figure[4], figure[5]);
	drawLine(figure[5], figure[6]);
	drawLine(figure[6], figure[7]);
	drawLine(figure[4], figure[7]);

	drawLine(figure[0], figure[4]);
	drawLine(figure[1], figure[5]);
	drawLine(figure[2], figure[6]);
	drawLine(figure[3], figure[7]);

	


	// Move cursor away from the figure
	moveCursor(22, 1);
	cout << endl;
}


Point setPoint(int rowValue, int colValue)
{
	Point temp;
	temp.row = rowValue;
	temp.col = colValue;
	return temp;
}


inline void clearScr()
{
	// clear screen & move cursor to top left corner
	printf(CSI "2J" CSI "1;1H");
}


inline void moveCursor(int row, int col)
{
	printf(CSI "%d;%dH", row, col);
}


void drawLine(Point start, Point end)
{
	double slope;	// line slope
	int st;			// line start col or start row
	int ed;			// line end col or end row

	// Draw a vertical line
	if (start.col == end.col)
	{
		// Determine line starting & ending row
		st = min(start.row, end.row);
		ed = max(start.row, end.row);

		// Plot points
		for (int y = st; y <= ed; y++)
		{
			moveCursor(y, start.col);
			printf("*");
		}
	}
	// Draw a non-vertical line
	else
	{
		// Calculate slope: m = (y2-y1)/(x2-x1)
		slope = ((double)start.row - end.row) / ((double)start.col - end.col);

		// Determine line starting & ending column
		st = min(start.col, end.col);
		ed = max(start.col, end.col);

		// Plot points
		for (int x = st; x <= ed; x++)
		{
			// For each x value, need to find corresponding y coordinate to graph
			// Slope intercept: y = mx + b, but must compensate for starting point
			int y = (int)(slope * ((double)x - start.col) + start.row);
			moveCursor(y, x);
			printf("*");
		}
	}
}
*/

// Partially filled arrays (deep dive)
/*
#include <iostream>
using namespace std;

// Prints a null-terminated array to the screen
void printArray1(const char data[]);

// Prints an array to the screen where usedSize is the number of items in the array
void printArray2(const int data[], int usedSize);

// Prints an array, data, to the screen where used is an array which indicates the
// positions in the data array which contain valid data
// Both the data array and the used array should be declared to be MAXSIZE
void printArray3(const int data[], const bool used[], const int MAXSIZE);

bool add1(char data[], const char newitem, const int MAX);

int main()
{
	const int MAX = 10;

	char array1[MAX] = { 'H', 'e', 'l', 'l', 'o'};


	int array2[MAX] = { 96, 87, 73, 88, 92, 19 };
	int usedSize = 6;

	int array3[MAX] = { 0, 96, 87, 0, 0, 88, 0, 92, 19, 0 };
	bool used[MAX] = { false, true, true, false, false, true, false, true, true, false };

	cout << "Array 1\n";
	if (add1(array1, 'Y', MAX))
		cout << "success\n";
	else
		cout << "no memory\n";
	printArray1(array1);

	cout << "\nArray2\n";
	printArray2(array2, usedSize);

	cout << "\nArray3\n";
	printArray3(array3, used, MAX);}

void printArray1(const char data[])
{
	for (int x = 0; data[x] != '\0'; x++)
	{
		cout << data[x] << endl;
	}
}

void printArray2(const int data[], int usedSize)
{
	for (int x = 0; x < usedSize; x++)
	{
		cout << data[x] << endl;
	}
}

void printArray3(const int data[], const bool used[], const int MAXSIZE)
{
	for (int x = 0; x < MAXSIZE; x++)
	{
		if (used[x])
		{
			cout << data[x] << endl;
		}
	}
}

bool add1(char data[], const char newitem, const int MAX)
{
	int x;
	for (x = 0; data[x] != '\0'; x++)
	{
	}

	if (x < MAX - 1)
	{
		data[x] = newitem;
		data[x + 1] = '\0';
		return true;
	}
	else
		return false;
	
}
*/

// Searching partially filed arrays
/*
#include <iostream>
using namespace std;

bool searchArray1(const int nums[], int usedSize, int key);
int searchArray2(const int nums[], int usedSize, int key);
int searchArray3(const int nums[], int usedSize, int startPos, int key);

int main()
{
	const int MAX = 10;
	int array1[MAX] = { 96, 92, 73, 88, 92, 19, 92 };
	int usedSize = 7;
	int key = 92;


	// Example 3
	int pos = searchArray3(array1, usedSize, 0, key);
	while (pos > -1)
	{
		cout << key << " found at position #" << pos << endl;
		pos = searchArray3(array1, usedSize, pos + 1, key);
	}


	// Example 2A
	pos = searchArray2(array1, usedSize, key);
	while (pos > -1)
	{
		array1[pos] = 56;
		pos = searchArray2(array1, usedSize, key);
	}


	// Example 2
	pos = searchArray2(array1, usedSize, key);
	if (pos > -1)
	{
		cout << key << " was found in the array\n";
		cout << "Changing " << key << " to 56\n";
		array1[pos] = 56;
	}
	else
		cout << key << " was not found in the array\n";


	// Example 1
	if (searchArray1(array1, usedSize, key))
		cout << key << " was found in the array\n";
	else
		cout << key << " was not found in the array\n";




	return 0;
}

bool searchArray1(const int nums[], int usedSize, int key)
{
	for (int count = 0; count < usedSize; count++)
	{
		if (key == nums[count])
			return true;
	}

	return false;
}

int searchArray2(const int nums[], int usedSize, int key)
{
	for (int count = 0; count < usedSize; count++)
	{
		if (key == nums[count])
			return count;
	}

	return -1;
}

int searchArray3(const int nums[], int usedSize, int startPos, int key)
{
	for (int count = startPos; count < usedSize; count++)
	{
		if (key == nums[count])
			return count;
	}

	return -1;
}
*/
/*
#include <iostream>
using namespace std;

void searchAll(const int nums[], int usedSize, int startPos, int key,
	int found[], int& foundSize);


int main()
{
	const int MAX = 10;

	int nums[MAX] = { 96, 92, 73, 88, 92, 19, 92 };
	int usedSize = 7;

	int found[MAX];
	int foundSize = 0;

	int key = 92;
	int changeTo = 56;


	// search the nums array
	searchAll(nums, usedSize, 0, key, found, foundSize);

	// go to each position of where key was found, and change
	// each one to a different value
	for (int x = 0; x < foundSize; x++)
	{
		nums[found[x]] = changeTo;
	}


	return 0;
}


void searchAll(const int nums[], int usedSize, int startPos, int key,
				   int found[], int& foundSize)
{
	// clear out the 'found' array
	foundSize = 0;

	for (int count = startPos; count < usedSize; count++)
	{
		if (key == nums[count])
		{
			found[foundSize] = count;
			foundSize++;
		}
	}
}
*/

// 2D arrays
/*
#include <iostream>
using namespace std;

const int MAXROWS = 4;
const int MAXCOLS = 3;

int nums2[MAXROWS][MAXCOLS];
void printArray(const int data[], const int usedSize);
void print2DArray(const int data[][MAXCOLS], const int usedRows, const int usedCols);

int main()
{
	//1D array
	const int MAXSIZE = 12;
	int nums[12];

	for (int i = 0; i < MAXSIZE; i++)
		nums[i] = 0;

	//2D array
	// now declared global

	// Can initalize by doing int nums2[MAXROWS][MAXCOLS] = { {56, 40, 97}, 
	//														{126, 208, 49}, 
	//														...}}
	
		// intit all Cols in a row
	for (int i = 0; i < MAXROWS; i++)
	{	//init all rows in a Col
		for (int x = 0; x < MAXCOLS; x++)
		{
			nums2[i][x] = 0;
		}
	}

	// Going through 2d arrays multiple ways
	/*
	//version 1.0
	// intit all Cols in a row
	for (int i = 0; i < MAXROWS; i++)
	{	//init all rows in a Col
		for (int x = 0; x < MAXCOLS; x++)
		{
			nums2[i][x] = 0;
		}
	}

	// Print values one per line

	for (int i = 0; i < MAXROWS; i++)
	{	//go through all rows in a Col
		for (int x = 0; x < MAXCOLS; x++)
		{
			cout << nums2[i][x] << "\n";
		}
	}
	cout << endl << endl;

	//one row per line

	for (int i = 0; i < MAXROWS; i++)
	{	//go through all rows in a Col
		for (int x = 0; x < MAXCOLS; x++)
		{
			printf("%4d", nums2[i][x]);
		}
		cout << endl;
	}

	//version 2.0

	const int MAXPOSITIONS = MAXROWS * MAXCOLS;

	for (int i = 0; i < MAXPOSITIONS; i++)
	{
		nums2[0][i] = 1;
	}

	//version 3.0 
	//pointer math
	int* temp = &nums2[0][0];

	for (int i = 0; i < MAXPOSITIONS; i++)
	{
		*temp = 0;
		temp = temp + 1;
	}
	//(ADDD COMMENT HERE)

	//Now with a function:
	
	//option 1 (per line)
	for (int i = 0; i < MAXROWS; i++)
	{	//go through all rows in a Col
		cout << "Row " << i << endl << endl;
		printArray(nums2[i], MAXCOLS);
	}

	//option 2 (per line, no control of "rows" spacing)
	//printArray(nums2[0], MAXCOLS * MAXROWS);


	print2DArray(nums2, MAXROWS, MAXCOLS);

	return 0;
}

void printArray(const int data[], const int usedSize) {
	for (int i = 0; i < usedSize; i++)
		cout << data[i] << endl;
}

void print2DArray(const int data[][MAXCOLS], const int usedRows, const int usedCols) {
	for (int i = 0; i < MAXROWS; i++)
	{	//go through all rows in a Col
		for (int x = 0; x < MAXCOLS; x++)
		{
			printf("%4d", nums2[i][x]);
		}
		cout << endl;
	}
}
*/

/*
#include <iostream>
#include <string>
using namespace std;

const int MAXCHARSPERNAME = 20;
const int MAXSTUDENTS = 50;

int main() {
	//init arrays w/ names
	char stuNames[MAXSTUDENTS][MAXCHARSPERNAME];
	string stuNames2[MAXSTUDENTS];
	char name[MAXCHARSPERNAME];
	int stuCount = 0;

	// initilize names
	/*
	snprintf(stuNames[0], MAXCHARSPERNAME, "%s", "John");
	stuCount++;
	snprintf(stuNames[1], MAXCHARSPERNAME, "%s", "Alice");
	stuCount++;

	//			0...1...2 per name

	//	snprintf(stuNames2[0], MAXCHARSPERNAME, "%s", "John");
	//		cant use because no function here does this so do

	stuNames2[0] = "John";
	stuNames2[1] = "Alice";
	
	//(ADD END COMMENT HERE)
	
	cout << "Enter up to " << MAXSTUDENTS << " names, or press ENTER to stop\n";

	bool stopLoop = false;

	while (stuCount < MAXSTUDENTS && !stopLoop) {
		cin.getline(stuNames[stuCount], MAXCHARSPERNAME);
		
		//cin getline gets the \n but doesnt store it, instead the code ends the string with a \0
		if (stuNames[stuCount][0] == '\0') {
			stopLoop = true;
		}
		else 
			stuCount++;
	}



	// to print:
	for (int i = 0; i < stuCount; i++) {
		cout << stuNames[i] << ", ";
	}
	cout << endl;
	for (int i = 0; i < stuCount; i++) {
		cout << stuNames2[i] << ", ";
	}

	return 0;
}

*/

//File handling

/*
#include <iostream>
#include <fstream>
using namespace std;

const int MAXSIZE = 20;


void printArray3(const int data[],  int used, const int MAXSIZE)
{
	for (int x = 0; x < used; x++)
	{
		cout << data[x] << endl;
	}
}

int main() {

	int nums[MAXSIZE] = { 12, 13, 14, 15, 16 };
	int usedsize = 5;

	int nums2[MAXSIZE];
	int usedsize2 = 0;

	//link variable to file (creates AND overwrites (if already created) the file)
	ofstream outFile;
	outFile.open("myfile.txt");

	//test connection:
	if (!outFile) {
		//if in here then couldnt open file
		cerr << "ERROR: output file could not be created\n";

		return 1;
	}

	for (int i = 0; i < usedsize; i++) {
		outFile << nums[i] << endl;
		//replace cout w/ the "file" to write to
			//can be any ofstream datatype file
	}

	outFile.close();

	cout << "Output file writtten!\n";

	//now to READ contents from a file

	//step 1
	ifstream inFile;

	//step 2
	inFile.open("myfile.txt");

	//test connection STEP 3:
	if (!inFile) {
		cerr << "ERROR: Input File could not be imported.\n";
		return 1;
	}

	//while (are numbers in file && array isnt full)

	//while (array isnt full && are numbers in file)
		//C does lazy eval. so if u have while(x === 0 && y++ <5) it does first half first only and only if its true then it does y++..etc

		// FOR INT the cin ">>" returns the "inFile ptr". So now if it returns that pointer its true but otherwise returns error message which will stop the loop
	//so if it gets a string it will fail too

	while (usedsize2 < MAXSIZE && inFile >> nums2[usedsize2]) {
		// CAN DELETE THIS HERE because it technically does the operation int he while statement. inFile >> nums2[usedsize2];
		//change cin to inFile
		usedsize2++;

	}
	// cin.getline turns to inFile.getline()


	printArray3(nums2, usedsize2, MAXSIZE);
	//step 5
	inFile.close();

	return 0;
}

*/


//RECURSION

/*
#include <iostream>
using namespace std;

long int factorial(int num);
long int factLoop(int num);
int corona(int n);

void towers(int numDisks, char start, char dest, char temp);
int* initArray() {
	static int LongtermArray[100];

	return LongtermArray;
}

int seqSearchRecursive(const int nums[], int startPos, int endPos, int key) {
	//base case:
	if (startPos > endPos)
		return -1;
	else if (nums[startPos] == key)
		return startPos;
	else
		return seqSearchRecursive(nums, startPos + 1, endPos, key);

	
}

int seqSearchLoop(const int nums[], int startPos, int endPos, int key) {

	for (int i = startPos; i < endPos; i++) {

		if (key == nums[startPos])
			return startPos;
	}
	return -1;
}

int binarySearchRecursive(const int nums[], int startPos, int endPos, int key) {
	//base case
	if (startPos > endPos)
		return -1;
	//base case 2
	int mid = (startPos + endPos) / 2;
	if (nums[mid] == key)
		return mid;

	if (key < nums[mid])
		return binarySearchRecursive(nums, startPos, mid-1, key);
	if (key > nums[mid])
		return binarySearchRecursive(nums, mid+1, endPos, key);

}

int main()
{
long int n = 3;
int num;
int* Array = initArray();
int test;

	// Call your function and print the result to the screen
	cout << factorial(n) << endl << endl;

	cout << factLoop(n);

	//corona example

	cout << "\nPersons infected on day 10 is : " << corona(5) << endl << endl;

	//towers of hanoi recursive
	cout << "Tower of Hanoi problem solver\nEnter Number of disks (auto 3): ";
	num = 3;
	cout << endl;
	towers(num, 'A', 'C', 'B');

	Array[5] = 20;
	Array[6] = 8;

	test = seqSearchRecursive(Array, 0, 10, 20);

	test = binarySearchRecursive(Array, 0, 50, 8);

	cout << "key found at pos: " << test;

	return 0;
}

void towers(int numDisks, char start, char dest, char temp) {

	//base case:
	if (numDisks == 1)
		cout << "Move " << start << " to peg " << dest << endl;
	// recursive cases
	
	else {
		towers(numDisks - 1, start, temp, dest);
		towers(1, start, dest, temp);
		towers(numDisks - 1, temp, dest, start);
	}

}

long int factorial(int num) {
	 long int fact = 1;

	if (num <= 20 && num >= 0) {
		for (int i = 1; i <= num; i++) {
			fact *= i;
		}
	}

	return fact;
}

long int factLoop(int num) {
	//look for base case first
	if (num == 1)
		return 1;

	//recursive cases now:
	//think of easiest problem now (2!) == 2 * 1
	return num * factLoop(num - 1);
}

int corona(int n) {

	//return # of of infections on day "n"
	if (n == 1 || n == 2) {
		return 1;
	}
	//test base cases + ONE recursive after (an where n == 3)
	return corona(n - 2) + corona(n - 1);
}

*/

//Memory (static vs dynamic)
/*
#include <iostream>
using namespace std;

int main() {
	//to get mem from heap:

	//in C:
		//what goes in is the # of bytes (4 = integer)
	////malloc(4);

		//in C++:
	//new int;

	//******both of those return a pointer to that space in memory****** //TO GET THE POINTER: C:
	int *p = (int*)malloc(sizeof(int));
	//int array of size 5 
	int* myArray = (int*)malloc(sizeof(int) * 5);
	//****IN C++:
	int* q = new int;
	int* myArray2 = new int[5];

	//MANDATORY to see if the above works
	if (p == NULL || myArray == NULL || q == NULL || myArray2 == NULL) {
		cerr << "COULDNT CREATE DYNAMIC (variable or array)";

		free(p);
		free(myArray);
		delete q;
		delete[] myArray2;
		return 1;
	}

	// IN THE ABOVE ARRAYS the (5) can be a reandom variable. MEANING you can create the array with a unique size like:
		//let user enter array size and instead of 5 call it a variable (size)
	*q = 23;
	delete q;
	q = new int;
	*q = 45;


	//****TO RETURN MEM****
	//in C
	free(p);
	p = NULL;
	//delete[] myArray;
	free(myArray);
	myArray = NULL;

	//in C++
	delete q;
	q = NULL;
	delete[] myArray2;
	myArray2 = NULL;

	return 0;
}*/

//LINKED LISTS

	//linked lists are dynamic, linear
	//COMPLETELY dyanmically allocated - DO NOT need to be resized
	//memory efficient(depends on size + stuff stored in it) && EASY to add to beginning of a linked list but HARD to add to end of a linked ist
	//head* -> [37][*] -> [24][*] -> [2][NULL]
/*
#include <iostream>
using namespace std;

typedef int ListItemType;

//for int
struct Node {
	ListItemType item;
	Node* next;

};

// Adds data to the end of a linked list
// head = a pointer to the list
// lastNode = a pointer to the last node in the list
// data = item that should be added to the list
// returns true if the item was added successfully
// and false if there is no memory to be able to add the new item
bool addToList(Node*& head, Node*& lastNode, ListItemType data);

// Deletes an entire linked list
// When finished, head will be NULL
void deleteList(Node*& head);

int main() {

	Node* head = NULL;
	Node* temp = NULL;

	Node* head = NULL;
	Node* lastNode = NULL;

	int num;
	//way no. 1 to do this
	/*
	
	//first node
	head = new Node;
	head->item = 3;
	head->next = NULL;

	//second node
	head->next = new Node;
	head->next->item = 6;
	head->next->next = NULL;

	//third node
	head->next->next = new Node;
	head->next->next->item = 47;
	head->next->next->next = NULL;

	delete head->next->next->next;
	delete head->next->next;
	delete head->next;
	delete head;

	////////COMMENT HERE TO WORK CODE

	//way no. 2 (EASIER)
	/*
	//create 3rd node
	head = new Node;
	head->item = 40;
	head->next = NULL;

	//create second node
	Node* temp = new Node;
	temp->item = 6;
	temp->next = head;
	head = temp;

	//create 1st node
	temp = new Node;
	temp->item = 3;
	temp->next = head;
	head = temp;

	//can write a loop for the above!
	////////////COMMENT HERE TO WORK CODE
	
	//looppp to enter nums!!
	/*
	cout << "Enter some integers. Enter -1 to quit:\n";
	cin >> num;

	// add first node to the list
	head = new Node;
	head->item = num;
	head->next = NULL;
	temp = head;

	cin >> num;

	// build the rest of the list
	while (num > -1)
	{
		temp->next = new Node;
		temp = temp->next;
		temp->item = num;
		temp->next = NULL;

		cin >> num;
	}


	// deallocate memory when finished    
	while (head != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	//////////// COMMENT HERE TO WORK CODE
	
	//same as loop above but as a function:
	cout << "Enter some integers. Enter -1 to quit:\n";
	cin >> num;

	// build the list
	while (num > -1)
	{
		if (!addToList(head, lastNode, num))
		{
			cerr << "ERROR: Out of memory\n";
			deleteList(head);
			exit(1);
		}
		cin >> num;
	}



	deleteList(head);
	return 0;
}

void deleteList(Node*& head)
{
	while (head != NULL)
	{
		Node* temp = head->next;
		delete head;
		head = temp;
	}
}

bool addToList(Node*& head, Node*& lastNode, ListItemType data)
{
	Node* temp = new Node;
	if (temp == NULL) return false;
	temp->item = data;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		lastNode = temp;
	}
	else
	{
		lastNode->next = temp;
		lastNode = temp;
	}

	return true;
}*/

#include <Windows.h>
#include<iostream>
using namespace std;

int main()
{
	int i = 0;

	while (i < 200) {
		SetCursorPos(500, 100);
		Sleep(50000);
		i += 1;
		SetCursorPos(500, 100);
		Sleep(50000);
		i += 1;

		cout << i << endl;
	}
		
	return 0;
}