// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

bool isNotEven(int x)
{
	if (x % 2 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isNotDiv2or3(int x)
{
	if ((x % 2 != 0) && (x % 3 != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int  main()
{
	ifstream file("C:/Users/Christopher/Documents/Freshmen Year/ComputerScience/input.txt");
	int x = 0;
	int counter = -1;
	int odd_counter = 0;
	int twoThreeCounter = 0;
	while (x != -1)
	{
		file >> x;
		if (isNotEven(x))
		{
			odd_counter++;
		}
		if (isNotDiv2or3(x))
		{
			twoThreeCounter++;
		}
		counter++;
	}
	cout << "Numbers read in = " << counter << endl;
	cout << "Numbers not even = " << odd_counter << endl;
	cout << "Numbers not divisible by 2 or 3  = " << twoThreeCounter << endl;

}

