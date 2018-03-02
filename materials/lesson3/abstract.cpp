#include "stdafx.h"
#include <iostream>

using namespace std;

// Абстрактный класс
class Shape
{
    string name;

  public:
    virtual void draw() = 0;
    virtual string getName() { return name; }
}

int main()
{
	return 0;
}