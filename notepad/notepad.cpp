#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

char priorityes;
char c;

static char buff[1024][1024];

char* name = new char[50];
char* description = new char[100];
char* date = new char[50];

char* contBuf = new char[100];
char* dateBuf = new char[100];
char* nameBuf = new char[100];
char* descriptionBuf = new char[100];
char* priorityBuf = new char[100];
char* prioritetBuf = new char[100];

int priority = 0;
int i = 0;
int number = 0;

string prioritet;
string sav;
string numberRecordList;
string fileName;
string fileNumPr;
string fileNumPusto;
string buffer;

void menu();
void returnMenu();
void previevRecordlist();
void readRecordList();
void searchRecordList();
void sortRecordList();
void sort1();
void sort2();
void sort3();
void redactorRecordFiles();
void deleteRecordList();
void cikl();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream filesNumber;

	menu();

	return 0;
	
}

void newRecordList()
{

		time_t rawtime;
		time(&rawtime);

		cout << " Добавить новую запись." << endl << endl;

		number++;

		cout << " Введите название записи: ";
		cin.get();
		gets_s(name, 50);

		cout << " Введите описание записи: ";
		cin.get();
		gets_s(description, 100);

		cout << " Выберите приоритет записи: " << endl << endl;
		cout << "   " << " Высокий - нажмите [1]" << endl;
		cout << "   " << " Средний - нажмите [2]" << endl;
		cout << "   " << " Низкий  - нажмите [3]" << endl << endl;
		cout << " Введите 1, 2 или 3: ";

		cin >> priorityes;
		
		switch (priorityes)
		{

		case '1':
			priority = 1;
			prioritet = "Высокий";
			cout << " Выбран приоритет - Высокий." << endl;
			break;
		case '2':
			priority = 2;
			prioritet = "Средний";
			cout << " Выбран приоритет - Средний." << endl;
			break;
		case '3':
			priority = 3;
			prioritet = "Низкий";
			cout << " Выбран приоритет - Низкий." << endl;
			break;
		default:
			cout << " Введено неверное значение. Приоритет по умолчанию будет \"Средний\"." << endl;
			priority = 2;
			prioritet = "Средний";
			break;
		}
														  
		cout << " Дата и время создания записи: " << ctime(&rawtime);
		date = ctime(&rawtime);

		ofstream filesNumber;
		filesNumber.open("number.txt", ios::out);
		filesNumber << number;
		filesNumber.close();

		numberRecordList = to_string(number);

		cikl();

		ofstream filesWriteListNumber;
		filesWriteListNumber.open(numberRecordList + ".txt", ios::out);
		filesWriteListNumber << endl;
		filesWriteListNumber << number << endl;
		filesWriteListNumber << name << endl;
		filesWriteListNumber << description << endl;
		filesWriteListNumber << prioritet << endl;
		filesWriteListNumber << date;
		filesWriteListNumber << priority << endl;
		filesWriteListNumber << endl;
		filesWriteListNumber.close();

		ofstream filesListNumber;
		filesListNumber.open("buffer.txt", ios::out);
		filesListNumber << endl;
		filesListNumber << " Запись номер: " << number << endl;
		filesListNumber << " Название:     " << name << endl;
		filesListNumber << " Описание:     " << description << endl;
		filesListNumber << " Приоритет:    " << prioritet << endl;
		filesListNumber << " Дата:         " << date << endl;
		filesListNumber << " ________________ " << endl;
		filesListNumber.close();
		
	cout << endl;
	cout << " Нажмите любую клавишу чтобы сохранить запись: ";
	cin >> sav;
	cout << endl << " Идёт сохранение, пожалуйста подождите";

	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " ." << endl;

	cout << " Запись успешно сохранена. " << endl << endl;
	Sleep(700);

	system("cls");
	previevRecordlist();

}
void previevRecordlist()
{

	cout << " Запись успешно создана: " << endl << endl;

	ifstream files("buffer.txt");

	while (!files.eof())
	{
		files.getline(buff[i], sizeof(buff));
		cout << buff[i] << endl;
		++i;
	}
	
	files.close();

	returnMenu();

}
void searchRecordList()
{
	cout << " Поиск записей";

}
void sortRecordList()
{

	string filename = "bufferWrite.txt";

	if (remove(filename.c_str()) == 0)
	{
		cout << endl << " " << " Обновление списка ";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
	}

	if (number == 0)
	{
		cout << endl << " Вы не создали ни одной записи для сортировки." << endl;

		Sleep(1000);
		cout << " Сейчас вы будете перенаправлены в меню";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
		menu();
	}

	else
	{
		do
		{
			cout << " Выберите приоритет записи: " << endl << endl;
			cout << "   " << " Высокий - нажмите [1]" << endl;
			cout << "   " << " Средний - нажмите [2]" << endl;
			cout << "   " << " Низкий  - нажмите [3]" << endl << endl;
			cout << " Введите 1, 2 или 3: ";

			cin >> c;

			switch (c)
			{
			case '1':
				system("cls");
				sort1();
				break;
			case '2':
				system("cls");
				sort2();
				break;
			case '3':
				system("cls");
				sort3();
				break;
			default:
				system("cls");
				cout << endl << " Введены неверные значения. Попробуйте еще раз." << endl;
				break;
			}
		} while (true);

	}
	
}	
void sort1()
{

	cout << " Список отсортирован по приоритету - Высокий" << endl;

	int count = 1;
	bool next = false;

	for (int j = 1; j < number; j++)
	{
		buffer = to_string(count);

		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> contBuf;
		filesWriteListNumber >> nameBuf;
		filesWriteListNumber >> descriptionBuf;
		filesWriteListNumber >> prioritetBuf;
		filesWriteListNumber >> dateBuf;
		filesWriteListNumber >> fileNumPr;


		if (fileNumPr == "1")
		{
			ofstream files;
			files.open("bufferWrite.txt", ios::app);
			files << endl;
			files << " Запись номер: " << contBuf << endl;
			files << " Название:     " << nameBuf << endl;
			files << " Описание:     " << descriptionBuf << endl;
			files << " Приоритет:    " << prioritetBuf << endl;
			files << " Дата:         " << dateBuf << endl;
			files << " ________________ " << endl;
			files.close();

			count++;
			next = false;
		}

		else
		{
			count++;
			next = true;
			continue;
		}

	}

	if (next == true)
	{
		cout << " Нет записей под этим приортитетом." << endl;
		returnMenu();
	}

	else
	{

		ifstream files("bufferWrite.txt");

		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}

		files.close();
	}


	returnMenu();
}
void sort2()
{

	cout << " Список отсортирован по приоритету - Средний." << endl;

	int count = 1;
	bool next = false;

	for (int j = 1; j < number; j++)
	{
		buffer = to_string(count);

		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> contBuf;
		filesWriteListNumber >> nameBuf;
		filesWriteListNumber >> descriptionBuf;
		filesWriteListNumber >> prioritetBuf;
		filesWriteListNumber >> dateBuf;
		filesWriteListNumber >> fileNumPr;


		if (fileNumPr == "2")
		{
			ofstream files;
			files.open("bufferWrite.txt", ios::app);
			files << endl;
			files << " Запись номер: " << contBuf << endl;
			files << " Название:     " << nameBuf << endl;
			files << " Описание:     " << descriptionBuf << endl;
			files << " Приоритет:    " << prioritetBuf << endl;
			files << " Дата:         " << dateBuf << endl;
			files << " ________________ " << endl;
			files.close();

			count++;
			next = false;
		}

		else
		{
			count++;
			next = true;
			continue;
		}

	}

	if (next == true)
	{
		cout << " Нет записей под этим приортитетом." << endl;
		returnMenu();
    }

	else
	{
		ifstream files("bufferWrite.txt");

		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}

		files.close();
	}

	returnMenu();
}
void sort3()
{

	cout << " Список отсортирован по приоритету - Низкий." << endl;

	int count = 1;
	bool next = false;
	
	for (int j = 1; j < number; j++)
	{
		buffer = to_string(count);

		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> contBuf;
		filesWriteListNumber >> nameBuf;
		filesWriteListNumber >> descriptionBuf;
		filesWriteListNumber >> prioritetBuf;
		filesWriteListNumber >> dateBuf;
		filesWriteListNumber >> fileNumPr;

		if (fileNumPr == "3")
		{
			ofstream files;
			files.open("bufferWrite.txt", ios::app);
			files << endl;
			files << " Запись номер: " << contBuf << endl;
			files << " Название:     " << nameBuf << endl;
			files << " Описание:     " << descriptionBuf << endl;
			files << " Приоритет:    " << prioritetBuf << endl;
			files << " Дата:         " << dateBuf << endl;
			files << " ________________ " << endl;
			files.close();

			count++;
			next = false;
			
		}

		else
		{
			count++;
			next = true;
			continue;
			
		}

	}

	if (next == true)
	{
		cout << " Нет записей под этим приортитетом." << endl;
		returnMenu();
	}
	else
	{
		ifstream files("bufferWrite.txt");

		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}

		files.close();
	}

		returnMenu();
}
void readRecordList()
{

	int count = 1;
	
	string filename = "bufferWrite.txt";

	if (remove(filename.c_str()) == 0)
	{
		cout << endl << " " << " Обновление списка ";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
	}

	for (int j = 1; j < number; j++)
	{
		buffer = to_string(count);

		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> contBuf;
		filesWriteListNumber >> nameBuf;
		filesWriteListNumber >> descriptionBuf;
		filesWriteListNumber >> prioritetBuf;
		filesWriteListNumber >> dateBuf;

		ofstream files;

		files.open("bufferWrite.txt", ios::app);
		files << endl;
		files << " Запись номер: " << contBuf << endl;
		files << " Название:     " << nameBuf << endl;
		files << " Описание:     " << descriptionBuf << endl;
		files << " Приоритет:    " << prioritetBuf << endl;
		files << " Дата:         " << dateBuf << endl;
		files << " ________________ " << endl;
		files.close();

		count++;
	}

	cout << " Список: " << endl;

	ifstream files("bufferWrite.txt");

	if (!files.is_open())
	{
		cout << endl << " Вы не создали ни одной записи" << endl;

		Sleep(1000);
		cout << " Сейчас вы будете перенаправлены в меню";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
		menu();
	}

	else
	{
		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}
		files.close();
	}

	returnMenu();

}
void redactorRecordFiles()
{

	time_t rawtime;
	time(&rawtime);

	cout << endl <<  " Изменить запись." << endl;

	ifstream filesListNumber("bufferDelete.txt");

	while (!filesListNumber.eof())
	{
		filesListNumber.getline(buff[i], sizeof(buff));
		cout << buff[i] << endl;
		++i;
	}
	filesListNumber.close();

	cout << endl;
	cout << " Введите название записи: ";
	cin.get();
	cin.getline(name, 50);

	cout << " Введите описание записи: ";
	cin.get();
	cin.getline(description, 100);

	cout << " Выберите приоритет записи: " << endl << endl;
	cout << "   " << " Высокий - нажмите [1]" << endl;
	cout << "   " << " Средний - нажмите [2]" << endl;
	cout << "   " << " Низкий  - нажмите [3]" << endl << endl;
	cout << " Введите 1, 2 или 3: ";

	cin >> priorityes;

	switch (priorityes)
	{

	case '1':
		priority = 1;
		cout << " Выбран приоритет - Высокий." << endl;
		break;
	case '2':
		priority = 2;
		cout << " Выбран приоритет - Средний." << endl;
		break;
	case '3':
		priority = 3;
		cout << " Выбран приоритет - Низкий." << endl;
		break;
	default:
		priority = 2;
		cout << " Введено неверное значение. Приоритет по умолчанию будет \"Средний\"." << endl;
		break;
	}

	cout << " Дата и время создания записи: " << ctime(&rawtime);
	date = ctime(&rawtime);
	
	numberRecordList = to_string(number);

	cikl();

	ofstream filesWriteListNumber;
	filesWriteListNumber.open(numberRecordList + ".txt", ios::out);
	filesWriteListNumber << endl;
	filesWriteListNumber << number << endl;
	filesWriteListNumber << name << endl;
	filesWriteListNumber << description << endl;
	filesWriteListNumber << prioritet << endl;
	filesWriteListNumber << date << endl;
	filesWriteListNumber << priority << endl;
	filesWriteListNumber << endl;
	filesWriteListNumber.close();

	cout << endl;
	cout << " Нажмите любую клавишу чтобы сохранить запись: ";
	cin >> sav;
	cout << endl << " Идёт сохранение, пожалуйста подождите";

	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " ." << endl;

	cout << " Запись успешно сохранена. " << endl << endl;
	Sleep(700);

	system("cls");
	menu();

}
void deleteRecordList()
{

	int del;
	int removeRedactor;

	cout << " У вас имеется " << number << " записи." << endl << endl;
	cout << " Введите номер записи которую хотите удалить. " << endl;
	
	do
	{
		cout << " Ввести номер от 1 до " << number << ": ";
		cin >> del; 
		fileName = to_string(del);

		ifstream filesNumRead(fileName + ".txt");
		filesNumRead >> contBuf;
		filesNumRead >> nameBuf;
		filesNumRead >> descriptionBuf;
		filesNumRead >> priorityBuf;
		filesNumRead >> dateBuf;

		ofstream filesListNumber;
		filesListNumber.open("bufferDelete.txt", ios::out);
		filesListNumber << endl;
		filesListNumber << " ________________ " << endl << endl;
		filesListNumber << " Запись номер: " << contBuf << endl;
		filesListNumber << " Название:     " << nameBuf << endl;
		filesListNumber << " Описание:     " << descriptionBuf << endl;
		filesListNumber << " Приоритет:    " << priorityBuf << endl;
		filesListNumber << " Дата:         " << dateBuf << endl;
		filesListNumber << " ________________ " << endl;
		filesListNumber.close();

		if (del > number || del <= 0)
		{
			cout << " Записи под номером " << del << " нет." << endl;
			cout << " Попробуйте снова. " << endl << endl;
			continue;
		}
		
		else
		{

			ifstream filesListNumber("bufferDelete.txt");

			while (!filesListNumber.eof())
			{
				filesListNumber.getline(buff[i], sizeof(buff));
				cout << buff[i] << endl;
				++i;
			}
			filesListNumber.close();

			cout << " Изменить запись - нажмите [1]" << endl;
			cout << " Удалить запись  - нажмите [2]" << endl;
		
			do
			{
				cout << " Выберите действие: ";
				cin >> removeRedactor;

				if (removeRedactor == 1)
				{
					system("cls");
					redactorRecordFiles();
					break;
				}
				if (removeRedactor == 2)
				{
					cout << " Выполняется удаление записи. Пожалуйста подождите ";

					string bufDel = "bufferDelete.txt";
					string p;

					if (remove(bufDel.c_str()) == 0)
					{
						Sleep(700);
						cout << " .";
						Sleep(700);
						cout << " .";
						Sleep(700);
						cout << " .";
						Sleep(700);
						cout << " ." << endl;

					}

					number--;

					ofstream filesNumber;
					filesNumber.open("number.txt", ios::out);
					filesNumber << number;
					filesNumber.close();

					p = fileName + ".txt";
					remove(p.c_str()) == 0;
				
					cout << endl << " Запись успешно удалена. " << endl << endl;
					Sleep(700);

					system("cls");
					menu();
					break;
				}
				else
				{
					cout << " Введено неверное значение. Повторите попытку" << endl;
					continue;
				}

			} while (true);
		}
	
	} while (true);
	
}
void menu()
{

	cout << " Список дел " << endl;
	cout << " ______________________ " << endl;
	cout << " 1. Добавить новую запись             - нажмите [1]" << endl;
	cout << " 2. Редактировать или удалить запись  - нажмите [2]" << endl;
	cout << " 3. Отобразить текущие записи         - нажмите [3]" << endl;
	cout << " 4. Найти запись из списка            - нажмите [4]" << endl;
	cout << " 5. Отсортировать список              - нажмите [5]" << endl;
	cout << " 6. Очистить весь список              - нажмите [6]" << endl;
	cout << " 7. Закрыть блокнот                   - нажмите [7]" << endl;

	char enter;
	ifstream filesNumber("number.txt");
	filesNumber >> number;

	do
	{
		cout << endl << " Выберите нужный пункт: ";
		cin >> enter;

		if (enter == '1')
		{
			system("cls");
			newRecordList();
			break;
		}
		if (enter == '2')
		{
			system("cls");

			if (number == 0)
			{
				cout << " У вас нет записей для удаления" << endl;

				Sleep(1000);
				cout << " Сейчас вы будете перенаправлены в меню";

				Sleep(700);
				cout << " .";
				Sleep(700);
				cout << " .";
				Sleep(700);
				cout << " .";
				Sleep(700);
				cout << " ." << endl;
				system("cls");
				menu();
			}

			else
			{
				system("cls");
				deleteRecordList();
			}

			break;
		}
		if (enter == '3')
		{
			system("cls");
			readRecordList();
			break;
		}
		if (enter == '4')
		{
			system("cls");
			searchRecordList();
			break;
		}
		if (enter == '5')
		{
			system("cls");
			sortRecordList();
			break;
		}
		if (enter == '6')
		{
			system("cls");
			cout << " Очистка списка." << endl << endl;

			int count = 1;
			string buffer;

			string filename = "bufferWrite.txt";
			string del;

			for (int i = 0; i < number; i++)
			{
				buffer = to_string(count);
				del = buffer + ".txt";
				remove(del.c_str()) == 0;
				
				count++;
			}

			if (remove(filename.c_str()) == 0)
			{
				cout << " Идет очистка списка, пожалуйста подождите ";
				Sleep(700);
				cout << " .";
				Sleep(700);
				cout << " .";
				Sleep(700);
				cout << " .";
				Sleep(700);
				cout << " ." << endl;

				ofstream filesNumber;
				filesNumber.open("number.txt", ios::out);
				filesNumber << "0";
				filesNumber.close();

				ofstream filesBuffer;
				filesBuffer.open("buffer.txt", ios::out);
				filesBuffer << "0";
				filesBuffer.close();

				cout << " Список успешно очищен.";
			}
			
			else 
			{
				cout << " Нет данных для удаления." << endl;
				Sleep(1000);
				cout << " Сейчас вы будете перенаправлены в меню";

				Sleep(700);
				cout << " .";
				Sleep(700);
				cout << " .";
				Sleep(700);
				cout << " .";
				Sleep(700);
				cout << " ." << endl;
				system("cls");
				menu();
			}

			Sleep(1000);
			system("cls");

			menu();
			break;;
		}
		if (enter == '7')
		{
			system("cls");
			cout << " Блокнот закрыт." << endl << endl;
			Sleep(1000);
			system("cls");
			break;
		}
		if (enter > '7' || enter == '0')
		{
			cout << " Введены неверные значения. Попробуйте ещё раз " << endl;
			continue;
		}

	} while (true);
}
void returnMenu()
{

	char menuExit;

	do
	{
		cout << endl << " Выйти в меню - нажмите [1]: ";
		cin >> menuExit;

		if (menuExit == '1')
		{
			system("cls");
			menu();
		}
		else
		{
			cout << endl << " Ведено неверное значение. Попробуйте ещё раз: " << endl << endl;
		}

	} while (true);
}
void cikl()
{

	char* temp;

	while (temp = strchr(name, ' '))
	{
		*temp = '_';
		strcpy_s(name + (strlen(name) - strlen(temp)), strlen(name), temp);
	}

	while (temp = strchr(description, ' '))
	{
		*temp = '_';
		strcpy_s(description + (strlen(description) - strlen(temp)), strlen(description), temp);
	}

	while (temp = strchr(date, ' '))
	{
		*temp = '_';
		strcpy_s(date + (strlen(date) - strlen(temp)), strlen(date), temp);
	}
}



