// Общий абстрактный класс стратегии (алгоритма).
struct Strategy
{
  virtual void execute() = 0;
};

// Предоставляет свою версию execute().
struct ConcreteStrategy1 : public Strategy
{
  virtual void execute() {}
};

// Предоставляет свою версию execute().
struct ConcreteStrategy2 : public Strategy
{
  virtual void execute() {}
};

// Хранит указатель на объект стратегии (агрегация).
struct Context
{
  Strategy *contextStrategy;

  Context(Strategy *strategy)
  {
    contextStrategy = strategy;
  }

  void executeAlgirithm()
  {
    contextStrategy->execute();
  }
}