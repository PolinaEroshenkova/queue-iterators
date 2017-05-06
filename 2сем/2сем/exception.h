#include<exception>
#include<iostream>
#pragma once
using namespace std;

class FileNotOpenException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Ошибка открытия файла";
	}
};
class EmptyFileException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Файл пуст";
	}
};
class FileReadException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Невозможно прочитать данные из файла";
	}
};
class InputException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Вы ввели недопустимый символ!";
	}
};
class MenuException
{
public:
	virtual const char* what() const throw()
	{
		return "Неверный выбор";
	}
};
class OutOfQueue : public exception{
public:
	virtual const char* what() const throw()
	{
		return "Выход за очередь";
	}
};
