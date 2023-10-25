#include <iostream>
#include "Functions.h"
using namespace std;

// function to swap the elements of an array
void swapArray(int myArray[], const int SIZE)
{
	// loop through half of the array
	for (int i = 0; i < SIZE / 2; i++)
	{
		// store the current element in a temporary variable
		int temp = myArray[i];

		// swap the current element with its counterpart from the end of the array
		myArray[i] = myArray[SIZE - 1 - i];
		myArray[SIZE - 1 - i] = temp;
	}
}