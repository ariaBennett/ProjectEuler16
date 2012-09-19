// Project Euler Problem 16.cpp : Defines the entry point for the console application.
//
//2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//What is the sum of the digits of the number 2^1000?

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void pause()
{
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}

bool isCarry(string carry)
{
	for (int i = 0; i < carry.length(); i++)
	{
		if (carry[i] == '1')
		{
			return true;
		}
	}
	return false;
}

string stringDoubler(string s)
{
	s = "0" + s;
	string carry;
	for (int i = 0; i < s.length(); i++)
	{
		carry += '0';
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1'){s[i] = '2';}
		else if (s[i] == '2'){s[i] = '4';}
		else if (s[i] == '3'){s[i] = '6';}
		else if (s[i] == '4'){s[i] = '8';}
		else if (s[i] == '5'){s[i] = '0';carry[i - 1] = '1';}
		else if (s[i] == '6'){s[i] = '2';carry[i - 1] = '1';}
		else if (s[i] == '7'){s[i] = '4';carry[i - 1] = '1';}
		else if (s[i] == '8'){s[i] = '6';carry[i - 1] = '1';}
		else if (s[i] == '9'){s[i] = '8';carry[i - 1] = '1';}
	}

	while ( isCarry(carry) )
	{
		string moreCarry = "";
		for (int i = 0; i < carry.length(); i++)
		{
			moreCarry += '0';
		}

		for (int i = 0; i < s.length(); i++)
		{
			if (carry[i] == '1')
			{
				if (s[i] == '0'){s[i] = '1';}else if (s[i] == '5'){s[i] = '6';}
				else if (s[i] == '1'){s[i] = '2';}else if (s[i] == '6'){s[i] = '7';}
				else if (s[i] == '2'){s[i] = '3';}else if (s[i] == '7'){s[i] = '8';}
				else if (s[i] == '3'){s[i] = '4';}else if (s[i] == '8'){s[i] = '9';}
				else if (s[i] == '4'){s[i] = '5';}else if (s[i] == '9'){s[i] = '0';}
			}
		}
		carry = moreCarry;
	}

	//if (s[0] == '0')
	//{
	//	s[0] = 255;
	//}

	return s;
}

long addDigits(string s)
{
	long digits = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i]=='1'){digits += 1;}else if (s[i]=='6'){digits += 6;}
		else if (s[i]=='2'){digits += 2;}else if (s[i]=='7'){digits += 7;}
		else if (s[i]=='3'){digits += 3;}else if (s[i]=='8'){digits += 8;}
		else if (s[i]=='4'){digits += 4;}else if (s[i]=='9'){digits += 9;}
		else if (s[i]=='5'){digits += 5;}
	}
	return digits;
}

int main()
{
	while (1)
	{
		string myString = "";
		int numTimes = 0;
		cout << "Input a number: ";
		cin >> myString;
		cout << "Input number of times to double it: ";
		cin >> numTimes;
		while (numTimes > 0)
		{
		myString = stringDoubler(myString);
		--numTimes;
		}
		cout << myString << endl;
		cout << "Value after adding digits together: " << addDigits(myString);
		pause();
	}
	return 0;
}

/*9174
	18348
	*/