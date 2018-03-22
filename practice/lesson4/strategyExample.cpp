#include <iostream>

using namespace std;

struct Movable
{
  virtual void move() = 0;
};

struct PetrolMove : public Movable
{
  virtual void move()
  {
    cout << "Перемещение на бензине" << endl;
  }
};

struct ElectricMove : public Movable
{
  virtual void move()
  {
    cout << "Перемещение на электричестве" << endl;
  }
};

class Car
{
protected:
  int passengersCount;
  string carModel;

public:
  Car(int passengersCount, string carModel, Movable *movable)
  {
    this->passengersCount = passengersCount;
    this->carModel = carModel;
    this->movable = movable;
  }

  Movable *movable;

  void move()
  {
    movable->move();
  }
};

int main()
{
  PetrolMove petrolMove;
  ElectricMove electricMove;

  Car car(4, "Lada", &petrolMove);
  car.move();

  car.movable = &electricMove;
  car.move();

  return 0;
}