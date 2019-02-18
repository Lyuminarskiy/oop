#include <exception>

using namespace std;

// Банковский счёт.
struct Account
{
  // Выдать кредит.
  virtual double getCredit(double sum, int month, int rate)
  {
    // Предусловие.
    if (sum < 0 || month > 12 || month < 1 || rate < 0)
      throw new exception("Некорректные данные");

    // Расчёт общей суммы кредита.
    double result = sum;
    for (int i = 0; i < month; i++)
      result += result * rate / 100;

    // Постусловие.
    if (sum >= 1000)
      result += 100;

    return result;
  }
};

// Банковский счёт с ограничениями.
struct MicroAccount : public Account
{
  // Выдать кредит.
  virtual double getCredit(double sum, int month, int rate)
  {
    // Предусловие.
    if (sum < 0 || month > 12 || month < 1 || rate < 0)
      throw new exception("Некорректные данные");

    // Расчёт общей суммы кредита.
    double result = sum;
    for (int i = 0; i < month; i++)
      result += result * rate / 100;

    // Ослабление постусловия.

    return result;
  }
};

// Получим ошибку при передаче MicroAccount.
void calculateCredit(Account* account)
{
  double sum = account->getCredit(1000, 1, 10);
  if (sum != 1200)
  {
    throw new exception("Неожиданная сумма при вычислениях");
  }
}

int main()
{
  Account *acc = new MicroAccount();
  calculateCredit(acc);

  return 0;
}