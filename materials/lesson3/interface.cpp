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