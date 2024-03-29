#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <iomanip>

using namespace std;

// Number of nations in each group .
const int row_nations = 4;
// Number of groups .
const int num_of_nations = 8;

// function of generating randum number
void drawGenerator(string [][num_of_nations],char[], int size);

int main()
{
	/********* Nations ********/	
	string nations[row_nations][num_of_nations] =
	{
		{
			// 1st class
			"RUSSIA","PORTUGAL","FRANCE","ARGENTINE","BRAZIL","GERMANY","BELGIUM","POLAND"
		},
		{
			// 2st class
			"URUGAUY","SPAIN","PERU","CROATIA","SWITZERLAND","MEXICO","ENGLAND","COLOMBIA"
		},
		{
			// 3rd class
			"EGYPT","IRAN","DENMARK","ICELAND","COSTA RICA","SWEDEN","TUNISIA","SENEGAL"
		},
		{
			// 4th class
			"KSA","MOROCCO","AUSTRALIA","NIGERIA","SERBIA","KOREA REPUBLIC","PANAMA","JAPAN" }
	};
	/********* END Nations ********/


	/********* Groups ********/
	char groups[num_of_nations] = { 'A','B','C','D','E','F','G','H' };
	/********* End Groups ********/

	/********* Get function ********/
	drawGenerator(nations,groups, num_of_nations);
	/********* End get function ********/

	return 0;

}

void drawGenerator(string nations[][num_of_nations],char groups[], int arraySize) {

	// for storing place to last randum number .
	bool stored[row_nations][num_of_nations] = { false };

	// seed rand
	srand(time(NULL));

	// num of groups = 8
	for (int colums = 0; colums < arraySize; colums++) {

		// Index of groups
		cout << setw(2);
		cout << groups[colums] << endl;

		// num of teams = 4
		for (int rows = 0; rows < row_nations; rows++) {

			// generating random numbers
			int randNum = rand() % num_of_nations;

			// check from random number is not repeating

			if (!stored[rows][randNum]) {

				// show result
				cout << setw(25);
				cout << (nations[rows][randNum]);

				// reserve place for this randum number = true (1)
				stored[rows][randNum] = true;

			}
			else {
				// do not jump to next row until you have checked that you get a new randum number 
				rows--;
			}

			} // end for loop -> rows

		cout << endl;
		
		} // end for loop -> colums

	// coded by
	cout << endl << "Programming by : Abdelsalam Mohammed Abdrabo" << endl << "Sec : 4" << endl << endl;

	} // end drawGenerator