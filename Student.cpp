#include "Student.h"
#include <conio.h>//для _getch() 
#include <stdio.h>//h-заголовок для функции fflush(stdin), очищающей входной поток
#include <iostream>
#include <stdlib.h>//очистка экрана
#define NUM_OF_OBJECTS 10// Количество элементов массива объектов
#define NUM_OF_MARKS 5// Количество элементов массива оценок
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
	int mark;
	cin >> mark;
	A[a] = 0;
	A[a] = mark;
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
	for (int i = 0; i < NUM_OF_MARKS; i++)
	{
		cout<<A[i] <<" ";
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
	for (int i = 0; i < NUM_OF_MARKS; i++)
	{
		A[i] = 0;
	}
	number = 0;
}
Student::~Student()
{
	delete[] initials;
	initials = NULL;
	for (int i = 0; i < NUM_OF_MARKS; i++)
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
	int choise2 = 0;
	cout << "Введите ФИО студента:\n";
	gets_s(str);
	obj.set_initials(str);
	cout << "Введите оценку студента:\n";
	for (int i = 0; i < NUM_OF_MARKS; i++)
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
	for (int i = 0; i < NUM_OF_OBJECTS; i++)
	{
		for (int j = 0; j < NUM_OF_MARKS; j++)
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
	cout << "\t\t\t\ Информация о студентах (не больше " << NUM_OF_OBJECTS << " записей):\n\n";
	for (int i = 0; i < NUM_OF_OBJECTS; i++)
	{
		if (*obj[i].take_initials() == ' ' &&  obj[i].take_number() == 0)//Если запись пуста, не производить вывод
		{
			cout << "Запись о студенте отсутсвует\n";
			continue;
		}
		cout << "----- " << count << " -----\n";
		count++;
		cout << obj[i];
		cout << "\n\n";
	}
	return;
}
void Student::sortt(Student obj[]) // сортировка по алфавиту
{
	for (int j = 0; j < NUM_OF_OBJECTS -1; j++)
	{
		for (int i = 0; i < NUM_OF_OBJECTS - 1; i++)
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
		for (int i = 0; i < NUM_OF_MARKS; i++)
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