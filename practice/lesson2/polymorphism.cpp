#include <iostream>

using namespace std;

struct Person
{
  virtual void printName() { cout << "I'm a Person!" << endl; }
};

struct Student : public Person
{
  void printName() { cout << "I'm a Student!" << endl; }
};

struct Worker : public Person
{
  void printName() { cout << "I'm a Worker!" << endl; }
};

void showInformation(Person *person) { person->printName(); }

int add(int left, int right) { return left + right; }
double add(double left, double right) { return left + right; }
char add(char left, char right) { return left + right; }
string add(string left, string right) { return left + right; }

int main()
{
  Person *person = new Person();
  Student *student = new Student();
  Worker *worker = new Worker();

  showInformation(person);
  showInformation(student);
  showInformation(worker);

  delete person;
  delete student;
  delete worker;

  add(125, 238);
  add(16.2, 18.3);
  add('a', 'z');
  add("Hellow,", " world!");

  return 0;
}