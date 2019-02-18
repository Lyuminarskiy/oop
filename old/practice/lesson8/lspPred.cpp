#include <exception>

using namespace std;

// Банковский счёт.
class Account
{
protected:
  double capital;

public:
  double getCapital()
  {
    return capital;
  }

  virtual void setCapital(double money)
  {
    // Предусловие.
    if (money < 0)
      throw new exception("Нельзя положить на счет меньше 0");

    capital = money;
  }
};

// Банковский счёт с ограничениями.
struct MicroAccount : public Account
{
  void setCapital(double money) override
  {
    // Предусловие.
    if (money < 0)
      throw new exception("Нельзя положить на счет меньше 0");

    // Усиление предусловия.
    if (money > 100)
      throw new exception("Нельзя положить на счет больше 100");

    capital = money;
  }
};

// Получим ошибку при передаче MicroAccount.
void initializeAccount(Account* account)
{
  account->setCapital(200);
}

int main()
{
  Account* acc = new MicroAccount();
  initializeAccount(acc);

  return 0;
}