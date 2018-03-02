#include "stdafx.h"
#include <iostream>

// Интерфейс
class Drawable
{
  public:    
    virtual void draw() = 0;
}

class Shape : public Drawable
{
    string name;

  public:
    virtual string getName() { return name; }
}

int main()
{
    return 0;
}

class Person {}
class Student : public Person {}
class Teacher : public Person {}

0..1
1
0..* или *
1..*

class Group { }

class Student {
  public:
    Group* group;
    Student()
}

class Body {}
class Head {}

class Human {
  public:
    Body* body;
    Head* head;

    Human() {
      body = new Body();
      head = new Head();
    }

    ~Human() {
      delete body;
      delete head;
    }
}

class Hat {}
class Pants {}
class Shirt {}

class Human2 {
  public:
    Hat* hat;
    Pants* pants;
    Shirt* shirt;

    Human(Hat* hat, Pants* pants, Shirt* shirt)
    {
      this->hat = hat;
      this->pants = pants;
      this->shirt = shirt;
    }
}

Visual Paradigm