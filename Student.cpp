#include "Student.h"
#include <conio.h>//для _getch() 
//#include < string.h > 
#include <stdio.h>//h-заголовок для функции fflush(stdin), очищающей входной поток
#include <iostream>
#include <stdlib.h>//очистка экрана
#define NUM 3// Количество элементов массива объектов
#define NUMO 2// Количество элементов массива оценок
//#include <cstring>
//#include <string.h>//h-заголовок для работы со строками

using namespace std;

void Student::set_initials(char *data)
{
	long int size = strlen(data);
	delete[] initials;
	initials = NULL;
	initials = new char[size + 1];
	strcpy(initials, data);
	return;
}
void Student::set_score2(int a)
{
	int p;
	cin >> p;
	A[a] = 0;
	A[a] = p;
	return;
}
void Student::set_number(char *data)
{
	number = 0;
	number = atoi(data);
	return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void Student::get_initials(void)
{
	cout << "ФИО студента: " << initials << "\n";
	return;
}
void Student::get_score2(void)
{

	cout << "Оценки студента: "  << "\n";
	for (int i = 0; i < NUMO; i++)
	{
		cout<<A[i];
	}
	cout << "\n";
	return;
}
void Student::get_number(void)
{
	cout << "Номер группы: " << number << "\n";
	return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
Student::Student()
{
	initials = new char[100];
	*(initials + 0) = ' ';
	*(initials + 1) = '\0';
	for (int i = 0; i < NUMO; i++)
	{
		A[i] = 0;
	}
	number = 0;
}
Student::~Student()
{
	delete[] initials;
	initials = NULL;
	for (int i = 0; i < NUMO; i++)
	{
		A[i] = 0;
	}

	number = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
istream &operator>>(istream &stream, Student &obj)
{
	fflush(stdin);
	char str[100];
	int data_number;
	int count = 0;
	bool flag = true;
	cout << "Введите ФИО студента:\n";
	gets_s(str);
	obj.set_initials(str);
	cout << "Введите оценку студента:\n";
	for (int i = 0; i < NUMO; i++)
	{
		obj.set_score2(i);
	}
	cout << "Введите номер группы студента:\n";
	getchar();
	gets_s(str);
	obj.set_number(str);
	return stream;
}
ostream &operator<<(ostream &stream, Student &obj)
{
	obj.get_initials();
	obj.get_score2();
	obj.get_number();
	return stream;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
char* Student::take_initials(void)
{
	return initials;
}
char* Student::take_score(int o)
{
	char str2[100];
	_itoa(A[o], str2, 10);
	return str2;
}
int Student::take_number(void)
{
	return number;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void Student::search_by_score(Student obj[])
{
	int flag = 0;
	char str[10];
	_itoa(2, str, 10); //Выбор оценки
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUMO; j++)
		{
			if (strcmp(obj[i].take_score(j), str) == 0)
			{
				flag++;
				cout << "\n"; //<< obj[i];
				obj[i].get_initials();
				obj[i].get_number();
				break;
			}
		}
	}
	if (flag == 0)
		cout << "\n" << "Студентов, имеющих хотя бы одну двойку, нет.\n";
	return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void Student::disp(Student obj[])
{
	int count = 1;
	cout << "\t\t\t\ Информация о студентах (не больше " << NUM << " записей):\n\n";
	for (int i = 0; i < NUM; i++)
	{
		if (*obj[i].take_initials() == ' '&&*obj[i].take_score(i) == ' '&&obj[i].take_number() == 0)//Если запись пуста, не производить вывод
			continue;
		cout << "----- " << count << " -----\n";
		count++;
		cout << obj[i];
		cout << "\n\n";
	}
	return;
}
void Student::sortt(Student obj[]) // сортировка по алфавиту
{
	for (int j = 0; j < NUM -1; j++)
	{
		for (int i = 0; i < NUM - 1; i++)
		{
			if(obj[i]< obj[i+1] )//if ((strcmp(obj[i].take_initials(), obj[i+1].take_initials()) > 0) && (strcmp(obj[i+1].take_initials(), " ") != 0) && (strcmp(obj[i].take_initials(), " ") != 0))
			{
				Student p;
				p = obj[i];
				obj[i] = obj[i + 1];
				obj[i + 1] = p;
			}
		}
	}
	
}

Student &Student ::operator= (const Student &obj) //перегрузка присваивания
{
	if (this == &obj)
	{
		return *this;
	}
	else
	{
		long int size = strlen(obj.initials);
		delete[] initials;
		initials = NULL;
		initials = new char[size + 1];
		strcpy(initials, obj.initials);
		for (int i = 0; i < NUMO; i++)
		{
			A[i] = obj.A[i];
		}
		number = obj.number;
		return *this;
	}
}
bool operator< (const Student &d1, const Student &d2) //перегрузка сравнения (для сравнения по алфавиту поля инициалов)
{
			if ((strcmp(d1.initials, d2.initials) > 0) && (strcmp(d2.initials, " ") != 0) && (strcmp(d1.initials, " ") != 0))
			{
				return true;
			}
			else 
				return false;
}