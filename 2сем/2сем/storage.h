#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdio.h>

using namespace std;
#pragma once
class storage
{
	string name;
	int amount;
	int cost;
	int number;
public:
	storage();
	~storage();
	storage& operator=(const storage&);
	void SetName(string);
	void SetAmount(int);
	void SetCost(int);
	void SetNumber(int);
	string GetName();
	int GetAmount();
	int GetCost();
	int GetNumber();
	friend ostream& operator<<(ostream&, storage);
	friend ofstream& operator<<(ofstream&, storage);
};