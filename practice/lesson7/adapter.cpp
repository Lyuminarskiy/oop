// Адаптируемый класс A.
struct ClassA
{
  void operationA() {}
};

// Адаптируемый класс B.
struct ClassB
{
  void operationB() {}
};

// Интерфейс, которому адаптируются классы A и B.
struct Target
{
  virtual void operation() = 0;
};

// Адаптер класса А.
class AdapterA : public Target
{
  ClassA classA;

public:
  virtual void operation() override
  {
    classA.operationA();
  }
};

// Адаптер класса B.
class AdapterB : public Target
{
  ClassB classB;

public:
  virtual void operation() override
  {
    classB.operationB();
  }
};