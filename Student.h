#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#define NUMO 2
using namespace std;
class Student
{
private:

	char *initials;//Указатель на строку, в которой содержится информация о ФИО
	int number;//Номер группы
	int A[NUMO]; //Массив оценок

public:

	void set_initials(char *data);//Ввод
	void set_number(char *data);
	void set_score2(int a);

	void get_initials(void);//Вывод 
	void get_number(void);
	void get_score2(void);
	
	char* take_initials(void);//Получение 
	char* take_score(int o);
	int take_number(void);

	friend ostream &operator<<(ostream &os, Student &obj);//Перегрузка
	friend istream &operator>>(istream &stream, Student &obj);

	friend bool operator< (const Student &d1, const Student &d2);
	Student& operator= (const Student &drob);

	static void search_by_score(Student obj[]);//Статический метод
	static void disp(Student obj[]);
	static void sortt(Student obj[]);

	Student();
	~Student();
};
#endif 