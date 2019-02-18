#include <vector>

using namespace std;

template <class T>
class Pool
{
private:
  struct Record
  {
    T *instance;
    bool used;
  };

  vector<Record> pool;

public:
  T *createNewObject()
  {
    for (size_t i = 0; i < pool.size(); ++i)
    {
      // Ищем свободный объект.
      if (!pool[i].used)
      {
        pool[i].used = true;
        return pool[i].instance;
      }
    }

    // Если свободного объекта нет, то создаём новый.
    Record record;
    record.instance = new T;
    record.used = true;

    pool.push_back(record);

    return record.instance;
  }

  // Указываем, что объект теперь свободен (а не удаляем его).
  void deleteObject(T *object)
  {
    for (size_t i = 0; i < pool.size(); ++i)
    {
      if (pool[i].instance == object)
      {
        pool[i].used = false;
        break;
      }
    }
  }

  // Реальное удаление объектов происходит в деструкторе.
  virtual ~Pool()
  {
    for (size_t i = 0; i < pool.size(); ++i)
      delete pool[i].instance;
  }
};