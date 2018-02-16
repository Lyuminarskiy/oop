#include "stdafx.h"
#include <iostream>

using namespace std;

struct Person
{
    // С virtual - переопределение
    // Без virtual - перекрытие
	virtual void printName() { cout << "I'm a Person!" << endl; }
};

struct Student : public Person
{
	void printName() { cout << "I'm a Student!" << endl; }
};

int main()
{
	Person *person1 = new Person();
	Person *person2 = new Student();

	person1->printName();
	person2->printName();

	delete person1;
	delete person2;

    return 0;
}