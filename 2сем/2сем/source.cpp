#include"file.h"
#include"checking.h"

const string successful = "��������� �������";
const string TYPE = "������� ";
const string NAME = "������������ �������";
const string SUM = "����������";
const string COST = "���������";
const string NUMBER = "����������������� �����";
const string PRODUCT = "�������";

file::file(string filename)
{
	int flags;
	this->filename = filename;
	fstream f(this->filename);
	flags = f.rdstate();
	if (flags & ios::badbit) throw FileNotOpenException();
}
file::~file()
{
	f.close();
}
void file::add()
{
	string name;
	int amount;
	int cost;
	int number;
	int flags;
	InputValidation validation;
	cout << TYPE << NAME << ": ";
	cin.sync();
	getline(cin, name);
	try{
		cout << TYPE << "����� " << SUM << " �������: ";
		cin >> amount;
		validation.CheckNumber(amount);
		cout << TYPE << COST << " ������ " << PRODUCT << ": ";
		cin >> cost;
		validation.CheckNumber(cost);
		cout << TYPE << NUMBER << " " << PRODUCT << ": ";
		cin >> number;
		validation.CheckNumber(number);
	}
	catch (InputException e)
	{
		cout << e.what() << endl;
		return;
	}
	f.open(filename, ios::app);
	flags = f.rdstate();
	if ((flags&ios::goodbit) == 0)
	{
		f << endl << endl
			<< "������������ �������: " <<
			name << endl <<
			"����� ����������: " <<
			amount << endl <<
			"��������� �� �����: " <<
			cost << endl <<
			"����������������� �����: " <<
			number;
	}
	f.clear(0);
	f.close();
	cout << successful << endl;
}

storage::storage()
{
	name = "";
	cost = 0;
	number = 0;
	amount = 0;
}
storage::~storage(){}
void storage::SetName(string temp)
{
	name = temp;
}
void storage::SetAmount(int temp)
{
	amount = temp;
}
void storage::SetCost(int temp)
{
	cost = temp;
}
void storage::SetNumber(int temp)
{
	number = temp;
}
string storage::GetName()
{
	return name;
}
int storage::GetAmount()
{
	return amount;
}
int storage::GetCost()
{
	return cost;
}
int storage::GetNumber()
{
	return number;
}
ostream& operator<<(ostream& cout, storage store)
{
	cout << endl << NAME << ": " << store.GetName() << endl;
	cout << "����� " << SUM << ": " << store.GetAmount() << endl;
	cout << COST << " �� �����: " << store.GetCost() << endl;
	cout << NUMBER << ": " << store.GetNumber();
	return cout;
}
storage& storage::operator=(const storage&obj)
{
	name = obj.name;
	amount = obj.amount;
	cost = obj.cost;
	number = obj.number;
	return *this;
}
ofstream& operator<<(ofstream& f, storage store){
	cout << endl << NAME << ": " << store.GetName() << endl;
	cout << "����� " << SUM << ": " << store.GetAmount() << endl;
	cout << COST << " �� �����: " << store.GetCost() << endl;
	cout << NUMBER << ": " << store.GetNumber();
	return f;
}

