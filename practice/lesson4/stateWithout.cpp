#include <iostream>

using namespace std;

enum WaterState
{
  SOLID,
  LIQUID,
  GAS
};

struct Water
{
  WaterState waterState;

  Water(WaterState waterState)
  {
    this->waterState = waterState;
  }

  void heat()
  {
    switch (waterState)
    {
    case WaterState::SOLID:
      cout << "Превращаем лед в жидкость" << endl;
      waterState = WaterState::LIQUID;
      break;

    case WaterState::LIQUID:
      cout << "Превращаем жидкость в пар" << endl;
      waterState = WaterState::GAS;
      break;

    case WaterState::GAS:
      cout << "Повышаем температуру водяного пара" << endl;
      break;
    }
  }
  void frost()
  {
    switch (waterState)
    {
    case WaterState::SOLID:
      cout << "Продолжаем заморозку льда" << endl;
      break;

    case WaterState::LIQUID:
      cout << "Превращаем жидкость в лед" << endl;
      waterState = WaterState::SOLID;
      break;

    case WaterState::GAS:
      cout << "Превращаем водяной пар в жидкость" << endl;
      waterState = WaterState::LIQUID;
      break;
    }
  }
};

int main()
{
  Water water(WaterState::LIQUID);
  water.heat();
  water.frost();
  water.frost();
}