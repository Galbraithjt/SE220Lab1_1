//============================================================================
// Name        : SE220Lab1_1.cpp
// Author      : Joshua Galbraith
// Version     :
// Copyright   : This is copyrighted under SoalerGaming
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 In the main method, create a 2D integer array, 2x2, and prompt the user to enter the 4 grade
 values (using nestedloops). Do a range check on the values and only accept them if they are between 1
 and 100. If the value is outside the range, report to the user that the value is either too low or too high and
 ask them to renter it.

Create a new integer vector with no size.

Use a Range-Based FOR loop to output the values of the array and, at the same time, add them to the vector.
After the loop, display the size of the vector to make sure it is indeed 4.

Create 5 integer counter variables to store the count of A, B, C, D, and F grades. Use a new Range-Based FOR
Loop on the vector and inside the loop, use a SWITCH statement to add how many A, B, C, D, and F grades there are
in the 4 values.

After the loop, display the results of the counters.

Create a new function called courseAverage (make sure to include the prototype of it before the main method!).
The function should not return anything. It will, however, take in 2 parameters. The first will be a POINTER to an integer.
The second, an integer indicating the total number of elements the pointer needs to access.

Inside the function, use the pointer to loop through the values in memory and add them up (storing the total in a new
variable). Then divide this by the total number of elements (the value of the 2nd parameter) to get the average.
Display the average.

In the main, call the function. Pass in the starting address of the vector and its size.
*/

#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std;

void gradeAverage(int *ptr, int);

int main()
{
	array<array < int , 2>, 2>gBookA;
	vector<int> gBookV(0); // vector declared
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int f=0;

	for (int flci=0; flci<2; flci++)
	{
		for (int flcii=0; flcii<2; flcii++)
		{
			do
			{
				cout << "Please enter grade value. Grade value must be between 1 and 100." << endl;
				cin >> gBookA[flci][flcii];
				if (gBookA[flci][flcii] < 1)
				{
					cout << "Number entered is to low please try again" << endl;
				}
				if (gBookA[flci][flcii] > 100)
				{
					cout << "Number entered is to high please try again" << endl;
				}
			}while((gBookA[flci][flcii] < 1) || (gBookA[flci][flcii] > 100));
		}
	}
	for(auto &a : gBookA)
	{
		for(int x : a)
		{
			cout << "Grade entered is: "<< x << endl;
			gBookV.push_back(x);
		}
	}
	cout << "Vector size is " << gBookV.size()<<endl;
	for(auto &g: gBookV)
	{
		switch (g / 10)
		{
			case 10:
			case 9:
			{
				++a;
				break;
			}
			case 8:
			{
				++b;
				break;
			}
			case 7:
			{
				++c;
				break;
			}
			case 6:
			{
				++d;
				break;
			}
			default:
			{
				++f;
				break;
			}
		}
	}
	cout << "The number of A's is " << a << "\nThe number of B's is " << b << "\nThe number of C's is " << c <<
			"\nThe number of D's is " << d << "\nThe number of F's is " << f << endl;
	gradeAverage(gBookV.data(), gBookV.size());
}//end Main

void gradeAverage (int *ptr, int counter)
{
	int total = 0;
	for(int flciii = 0; flciii<counter; flciii++)
	{
		total = ptr[flciii] + total;
	}
	cout << "Grade Average is " << total / counter << endl;
}
