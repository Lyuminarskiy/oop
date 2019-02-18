#include <exception>

using namespace std;

// Банковский счёт.
class Account
{
protected:
  // Инвариант (всегда больше 100).
  double capital;

public:
  double getCapital()
  {
    return capital;
  }

  virtual void setCapital(double money)
  {
    // Предусловие.
    if (money < 100)
      throw new exception("Некорректная сумма");

    capital = money;
  }
};

// Банковский счёт с ограничениями.
struct MicroAccount : public Account
{
  void setCapital(double money) override
  {
    // Нарушается инвариант родительского класса.
    capital = money;
  }
};