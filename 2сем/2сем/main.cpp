#include"checking.h"
#include"exception.h"
#include"file.h"
#include"menu.h"
#include"queue.h"
#include"storage.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	int choice;
	int flags;
	char error;
	MENU menu;
	queue<storage> store;
	try{
		while (1)
		{
			file my("file.txt");
			while (1)
			{
				menu.MainMenu();
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
					break;
				}
				switch (choice)
				{
				case 1:
					system("cls");
					my.add();
					system("pause");
					system("cls");
					break;
				case 2:
					system("cls");
					store.clear();
					my.read(store);
					store.display();
					cout << "Выполнено успешно" << endl;
					system("pause");
					system("cls");
					break;
				case 3:
					store.clear();
					my.read(store);
					store.pop();
					my.ReWrite(store);
					system("pause");
					system("cls");
					break;
				case 4:
					store.clear();
					my.read(store);
					edit(store);
					my.ReWrite(store);
					system("pause");
					system("cls");
					break;
				default:
					system("cls");
					cout << "Нет такого пункта меню" << endl;
					system("pause");
					system("cls");
				}
			}
		}
	}
	catch (FileNotOpenException e)
	{
		cout << e.what() << endl;
	};
}
