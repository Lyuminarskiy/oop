#include <iostream>

using namespace std;

// Абстрактный класс
class Shape
{
  string name;

public:
  virtual void draw() = 0;
  virtual string getName() { return name; }
};

// Интерфейс
struct Drawable
{
  virtual void draw() = 0;
};

class Shape : public Drawable
{
  string name;

public:
  virtual string getName() { return name; }
};

// Ассоциация
class Person {};
class Student : public Person {};
class Teacher : public Person {};

class Group {};
struct Student2
{
  Group* group;
  Student2();
};

// Композиция
class Body {};
class Head {};
class Human
{
  Body* body;
  Head* head;

public:
  Human()
  {
    body = new Body();
    head = new Head();
  }

  ~Human()
  {
    delete body;
    delete head;
  }
};

// Аргегация
class Hat {};
class Pants {};
class Shirt {};
class Human2
{
  Hat* hat;
  Pants* pants;
  Shirt* shirt;

public:
  Human2(Hat* hat, Pants* pants, Shirt* shirt)
  {
    this->hat = hat;
    this->pants = pants;
    this->shirt = shirt;
  }
};