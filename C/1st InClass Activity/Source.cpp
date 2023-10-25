// Jason Avila-Soria 1st In Class Activity
// Jungyeon Park
// Keshawn Mallery

#include <iostream>
#include <cmath>
#include "SomeFunction.h"

using namespace std;

const int LOWERLIMIT = 0, UPPERLIMIT = 13;

int main()
{
	int numSquared, twoPowerI;
	
	//this displays the top menu portion of what the numbers in the formula correspond to (formatted for the code in the comments)
	/*
	cout << "     |\t" << " 2" << " | " << " N\n";
	cout << "   N" << " |\t" << "N" << "  | " << "2\n";
	cout << "-----+-----+------\n";
	*/
	//updated code for formatted printf function
	cout << "   |   2 |  N\n";
	cout << " N |  N  | 2\n";
	cout << "---+-----+-----\n";
	

	/*for (int i = 0; i < 13; i++)
	{
		numSquared = i * i;
		twoPowerI = pow(2, i);

		// the \t is for the spacing and the rest gives the values for their respective formulas.
		if (i < 10)
		{
			if (numSquared > 9 && numSquared < 100)
			{
				if (twoPowerI > 9 && twoPowerI < 100)
				{
					cout << "   " << i << " | " << numSquared << "  | " << twoPowerI << endl;
				}
				else
				{
					cout << "   " << i << " | " << numSquared << "  | " << twoPowerI << endl;
				}
			}
			else
			{
				cout << "   " << i << " | " << numSquared << "   | " << twoPowerI << endl;
			}
		}
		else if (i > 9)
		{
			if (numSquared > 99)
			{
				if (twoPowerI > 9 && twoPowerI < 100)
				{
					cout << "   " << i << " | " << numSquared << "  | " << twoPowerI << endl;
				}
				else
				{
					cout << "  " << i << " | " << numSquared << " | " << twoPowerI << endl;
				}
				
			}
		
		}
	}
	*/

	for (int i = LOWERLIMIT; i < UPPERLIMIT; i++)
	{
		numSquared = i * i;
		twoPowerI = pow(2, i);
		printf("%2d | %3d | %4d\n", i, numSquared, twoPowerI);
	}
	someFunction();
	cout << endl;

	printf("%4s", "Quarter");
	printf("%4s", "Quarter");
	return 0;
}

