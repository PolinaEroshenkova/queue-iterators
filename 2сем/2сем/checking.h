#include<iostream>
#include "exception.h"
#include<string>
using namespace std;

class InputValidation
{
public:
	void CheckNumber(int number)
	{
		int flags;
		string error;
		flags = cin.rdstate();
		if (flags & ios::failbit)
		{
			cin.clear(0);
			cin >> error;
			throw InputException();
		}
	}

	int CheckString(string line){
		int counter = 0;
		unsigned int i;
		for (i = 0; i < line.length(); i++)
		{
			if ((line[i] >= 32 && line[i] <= 47) || (line[i] >= 58)) return 0;
			else counter++;
		}
		if (counter == i) { return 1; }
		else return -1;
	}
};