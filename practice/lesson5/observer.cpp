#include <list>

using namespace std;

// Представляет наблюдаемый объект.
struct Observable
{
  // Добавить наблюдателя.
  virtual void addObserver(Observer *observer) = 0;
  // Удалить наблюдателя.
  virtual void removeObserver(Observer *observer) = 0;
  // Уведомить наблюдателей.
  virtual void notifyObservers() = 0;
};

// Конкретная реализация наблюдаемого объекта.
class ConcreteObservable : public Observable
{
  // Список наблюдателей.
  list<Observer *> observers;

public:
  virtual void addObserver(Observer *observer)
  {
    observers.push_back(observer);
  }

  virtual void removeObserver(Observer *observer)
  {
    observers.remove(observer);
  }

  virtual void notifyObservers()
  {
    for (Observer *observer : observers)
      observer->update();
  }
};

// Представляет наблюдателя, который подписывается
// на все уведомления наблюдаемого объекта.
struct Observer
{
  // Вызывается наблюдаемым объектом для уведомления наблюдателя.
  virtual void update() = 0;
};

// Конкретная реализация наблюдателя.
struct ConcreteObserver : public Observer
{
  virtual void update() {}
};