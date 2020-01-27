#include "Student.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <algorithm>
#define NUM_OF_OBJECTS 10 // Количество элементов массива объектов
using namespace std;
int main()
{
	Student stud[NUM_OF_OBJECTS];//Массив объектов 
	setlocale(LC_ALL, "rus");
	char str[100];// Строка с клавиатуры
	int choise,choise2;//Переменные для номера команды в меню и выбора нужного элемента массива типа Student
	bool flag = true; 
	int cnt = 0;
	while (1)//Основной цикл работы программы
	{
		while (1)//Цикл для проверки правильности введенной команды в меню
		{
			cout << "1 - Ввод данных о всех стундентах\n2 - Вывод данных о всех студентах (в алфавитном порядке)\n3 - Вывод двоишников\n4 - Выход\n\n";
			cout << "Выберите действие:\n";
			gets_s(str);
			cnt = 0;
			while (str[cnt])//Цикл проверки на то, является ли введенная заявка числом
			{
				if (isdigit(str[cnt]))
				{
					flag = true;
					cnt++;
				}
				else
				{
					cnt = 0;
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				cout << "Ошибка ввода. Повторите ввод.\n";
				_getch();
				system("cls");
				continue;
			}
			else
			choise = atoi(str);//из строки в число
			if (choise > 4 || choise < 1)
			{
				cout << "Ошибка.Команда отсутсвует. Повторите ввод.";
				_getch();
				system("cls");
				continue;
			}
			else
				break;
		}
		switch (choise)
		{

		case 1: system("cls");//Ввод всех данных
			for (int i = 0; i < NUM_OF_OBJECTS; i++)
			{
					system("cls");
					cin >> stud[i];
					cout << "Чтобы закончить ввод введите '1', чтобы продолжить введите любой символ отличный от '1':\n";
					cin >> choise2;
					if (choise2 == 1)
					{
						cout << "\nВведены данные о(об) " << i+1 << " студентах(е).\n";
						break;
					}
					//cin.clear();
					//while (cin.get() != '\n');
					cin.get();
			}
			choise2 = 0;
			Student::sortt(stud);//Сортировка объектов по алфавиту 
			cout << "\nВвод окончен. Нажмите любую кнопку.\n";
			_getch();
			system("cls");
			break;

		case 2: system("cls");//Вывод всей информации 
			Student::disp(stud);//Вывод всей информации
			cout << "\nНажмите любую кнопку.\n";
			_getch();
			system("cls");
			break;

		case 3: system("cls");
			cout << "Список студентов имеющих хотябы одну двойку:\n";
			Student::search_by_score(stud);
			cout << "\nНажмите любую кнопку.\n";
			_getch();
			system("cls");
			break;

		case 4://Выход из программы
			cout << "\nПрограмма завершена.\n";
			_getch();
			return 0;
			break;
		}
	}
}