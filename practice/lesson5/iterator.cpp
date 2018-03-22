#include <iostream>
#include <initializer_list>

using namespace std;

template <class T>
struct Container;

// Абстрактный итератор.
template <class T>
struct Iterator
{
  virtual T getCurrentItem() = 0;
  virtual T getFirstItem() = 0;
  virtual T getNextItem() = 0;
  virtual bool isDone() = 0;
};

// Конкретная реализация итератора для обхода объекта типа Container.
template <class T>
class ConcreteIterator : public Iterator<T>
{
  int current;
  Container<T> *container;

public:
  ConcreteIterator(Container<T> *container)
  {
    this->container = container;
  }

  virtual T getCurrentItem()
  {
    return container->getItem(current);
  }

  virtual T getFirstItem()
  {
    return container->getItem(0);
  }

  virtual T getNextItem()
  {
    current++;
    return isDone() ? T() : getCurrentItem();
  }

  virtual bool isDone()
  {
    return current >= container->getSize();
  }
};

// Абстрактный контейнер.
template <class T>
struct Container
{
  virtual Iterator<T> *createIterator() = 0;
  virtual T getItem(int position) = 0;
  virtual int getSize() = 0;
};

// Конкретная реализация контейнера, хранит элементы.
template <class T>
class ConcreteContainer : public Container<T>
{
  int size;
  T *items;

public:
  ConcreteContainer(initializer_list<T> list)
  {
    size = list.size();
    items = new T[size];

    int i = 0;
    for (T item : list)
    {
      items[i] = item;
      ++i;
    }
  }

  ~ConcreteContainer()
  {
    delete[] items;
  }

  virtual Iterator<T> *createIterator()
  {
    return new ConcreteIterator<T>(this);
  }

  virtual T getItem(int position)
  {
    return items[position];
  }

  virtual int getSize()
  {
    return size;
  }
};

int main()
{
  ConcreteContainer<int> container = {1, 2, 3, 4, 5};
  Iterator<int> *iterator = container.createIterator();

  int item = iterator->getFirstItem();
  while (!iterator->isDone())
  {
    cout << item << endl;
    item = iterator->getNextItem();
  }

  return 0;
}