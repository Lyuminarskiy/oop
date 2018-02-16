#include "stdafx.h"
#include <iostream>

using namespace std;

class Counter
{
    static int count;

  public:
    static void printCount() { cout << count << endl; }
    void increment() { count++; }
};

int Counter::count = 0;

int main()
{
    Counter c1, c2;
    Counter::printCount();

    c1.increment();
    Counter::printCount();

    c2.increment();
    Counter::printCount();

    c1.increment();
    Counter::printCount();

    return 0;
}