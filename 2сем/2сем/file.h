#include<iostream>
#include<fstream>
#include"storage.h"
#include"queue.h"
#include"exception.h"
using namespace std;

class file
{
	string filename;
	fstream f;
	int N;
public:
	file(string);
	void add();
	template<class T>
	void ReWrite(queue<T>);
	void Delete();
	void clear();
	template<class T>
	int read(queue<T>&);
	~file();
	template<class T>
	friend ostream& operator<<(ostream& f, myiterator<T> iter)
	{
		f << iter.GetCurrent();
		return f;
	};
};

template<class T>
int file::read(queue<T>& store)
{
	storage tmp;
	string name;
	string buf;
	int amount;
	int cost;
	int number;
	int flags;
	try{
		f.open(filename, ios_base::in);
		flags = f.rdstate();
		if (flags & (ios::badbit | ios::failbit))
		{
			throw FileNotOpenException();
		}
		if (flags & ios::eofbit)
		{
			throw EmptyFileException();
		}
	}
	catch (FileReadException e)
	{
		cout << e.what() << endl;
		system("pause");
		f.clear(0);
		f.close();
		return 0;
	}
	catch (EmptyFileException &e)
	{
		cout << e.what() << endl;
		system("pause");
		f.clear(0);
		f.close();
		return 0;
	}
	catch (...)
	{
		exception e;
		cout << e.what() << endl;
		system("pause");
		f.clear(0);
		f.close();
		return 0;
	}
	f.seekg(0, ios_base::beg);
	flags = f.rdstate();
	while (!flags&ios::eofbit)
	{
		f >> name >> name >> name;
		tmp.SetName(name);
		f >> buf >> buf >> amount;
		tmp.SetAmount(amount);
		f >> buf >> buf >> buf >> cost;
		tmp.SetCost(cost);
		f >> buf >> buf >> number;
		tmp.SetNumber(number);
		store.push(tmp);
		flags = f.rdstate();
	}
	f.clear();
	f.close();
	return 1;
}

template<class T>
void file::ReWrite(queue<T> store)
{
	f.open(filename, ios::out);
	myiterator<storage> iter;
	for (iter = store.begin(); iter != store.end(); iter++)
	{
		f << *iter;
	}
	f.close();
}

template<class T>
void edit(queue<T>& store)
{
	int number;
	string error;
	int flags;
	T data;
	InputValidation validation;
	MENU menu;
	string temp;
	int choice;
	int counter = 0;
	myiterator<T> iter;
	queue<T> *buffer;
	try{
		cout << "Идентификационный номер изделия: ";
		cin >> number;
		validation.CheckNumber(number);
	}
	catch (InputException &e)
	{
		cout << e.what() << endl;
		return;
	}
	menu.MenuEditing();
	try{
		cin >> choice;
		flags = cin.rdstate();
		if (flags & ios::failbit)
		{
			cin.clear(0);
			cin >> error;
			throw MenuException();
		}
	}
	catch (MenuException &e)
	{
		cout << e.what() << endl;
		return;
	}
	system("cls");
	cin.sync();
	for (iter = store.begin(); iter != store.end(); iter++)
	{
		buffer = iter.GetCurrent();
		data = buffer->GetData();
		if (number == data.GetNumber())
		{
			try{
				cout << "Введите новое поле: ";
				cin.sync();
				getline(cin, temp);
				validation.CheckString(temp);
			}
			catch (...)
			{
				cout << "Некорректный ввод" << endl;
				return;
			}
			counter++;
			switch (choice)
			{
			case 1:
				data.SetName(temp);
				buffer->SetData(data);
				break;
			case 2:
				data.SetAmount(atoi(temp.c_str()));
				buffer->SetData(data);
				break;
			case 3:
				data.SetCost(atoi(temp.c_str()));
				buffer->SetData(data);
				break;
			case 4:
				data.SetNumber(atoi(temp.c_str()));
				buffer->SetData(data);
				break;
			default:
				system("cls");
				cout << "Нет такого пункта меню" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	cout << "Выполнено успешно" << endl;
}