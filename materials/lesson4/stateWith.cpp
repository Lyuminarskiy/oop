#include <iostream>

using namespace std;

struct WaterState
{
  virtual void heat(Water* water) = 0;
  virtual void frost(Water* water) = 0;
};

struct SolidWaterState : public WaterState
{
  virtual void heat(Water* water)
  {
    cout << "Превращаем лед в жидкость" << endl;
    water->state = new LiquidWaterState();
  }

  virtual void frost(Water* water)
  {
    cout << "Продолжаем заморозку льда" << endl;
  }
};

struct LiquidWaterState : public WaterState
{
  virtual void heat(Water* water)
  {
    cout << "Превращаем жидкость в пар" << endl;
    water->state = new GasWaterState();
  }
  virtual void frost(Water* water)
  {
    cout << "Превращаем жидкость в лед" << endl;
    water->state = new SolidWaterState();
  }
};

struct GasWaterState : public WaterState
{
  virtual void heat(Water* water)
  {
    cout << "Повышаем температуру водяного пара" << endl;
  }

  virtual void frost(Water* water)
  {
    cout << "Превращаем водяной пар в жидкость" << endl;
    water->state = new LiquidWaterState();
  }
};

struct Water
{
  WaterState* state;
  
  Water(WaterState* state)
  {
    this->state = state;
  }

  void heat()
  {
    state->heat(this);
  }
  void frost()
  {
    state->frost(this);
  }
};

int main()
{
  Water water(new LiquidWaterState());
  water.heat();
  water.frost();
  water.frost();
}