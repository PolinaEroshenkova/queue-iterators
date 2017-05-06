#include<iostream>
using namespace std;

class MENU
{
public:
	void MainMenu(){
		cout << "1.Добавить данные в файл" << endl;
		cout << "2.Просмотр данных из файла" << endl;
		cout << "3.Удалить запись" << endl;
		cout << "4.Редактировать данные" << endl;
		cout << "5.Выход" << endl;
		cout << "Ваш выбор: ";
	};
	void MenuEditing(){
		cout << "Редактировать: " << endl;
		cout << "1.Название" << endl;
		cout << "2.Количество" << endl;
		cout << "3.Стоимость" << endl;
		cout << "4.Номер" << endl;
		cout << "5.Выход в главное меню" << endl;
		cout << "Ваш выбор: ";
	};
};