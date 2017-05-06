#include<exception>
#include<iostream>
#pragma once
using namespace std;

class FileNotOpenException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "������ �������� �����";
	}
};
class EmptyFileException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "���� ����";
	}
};
class FileReadException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "���������� ��������� ������ �� �����";
	}
};
class InputException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "�� ����� ������������ ������!";
	}
};
class MenuException
{
public:
	virtual const char* what() const throw()
	{
		return "�������� �����";
	}
};
class OutOfQueue : public exception{
public:
	virtual const char* what() const throw()
	{
		return "����� �� �������";
	}
};
