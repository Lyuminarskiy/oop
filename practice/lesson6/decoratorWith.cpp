#include <string>

using namespace std;

class Pizza
{
  protected:
    string name;

  public:
    Pizza(const string &name) : name(name) {}
    virtual int getCost() = 0;
    virtual const string& getName()
    {
        return name;
    }
};

struct ItalianPizza : public Pizza
{
    ItalianPizza() : Pizza("Итальянская пицца") {}
    virtual int getCost() override
    {
        return 10;
    }
};

struct AmericanPizza : public Pizza
{
    AmericanPizza() : Pizza("Американская пицца") {}
    virtual int getCost() override
    {
        return 8;
    }
};

class PizzaDecorator : public Pizza
{
protected:
    Pizza *pizza;

public:
    PizzaDecorator(const string &name, Pizza *pizza) :
        Pizza(name), pizza(pizza) {}
};

struct TomatoPizza : public PizzaDecorator
{
    TomatoPizza(Pizza* pizza) :
        PizzaDecorator(pizza->getName() + " с томатами", pizza) {}
    
    virtual int getCost() override
    {
        return pizza->getCost() + 3;
    }
};

struct CheesePizza final : public PizzaDecorator
{
    CheesePizza(Pizza* pizza) :
        PizzaDecorator(pizza->getName() + " с сыром", pizza) {}
    
    virtual int getCost() override
    {
        return pizza->getCost() + 5;
    }
};

void main()
{
    // Итальянская пицца с томатами.
    Pizza* pizza1 = new ItalianPizza();
    pizza1 = new TomatoPizza(pizza1);

    // Итальянская пицца с сыром.
    Pizza* pizza2 = new ItalianPizza();
    pizza2 = new CheesePizza(pizza2);

    // Американская пицца с томатами и сыром.
    Pizza* pizza3 = new AmericanPizza();
    pizza3 = new TomatoPizza(pizza3);
    pizza3 = new CheesePizza(pizza3);
}