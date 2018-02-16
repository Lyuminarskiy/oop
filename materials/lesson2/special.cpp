#include "stdafx.h"
#include <iostream>

using namespace std;

struct Backup final {
	static void makeBakup(string path) {}
};

struct Printer final {
	static void print(string text) {}
};

int main()
{
	Backup::makeBakup("C:/myBackups/");
	Printer::print("Hello, world!");

    return 0;
}