#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Observable
{
  virtual void addObserver(Observer *observer) = 0;
  virtual void removeObserver(Observer *observer) = 0;
  virtual void notifyObservers(const string &message) = 0;
};

// Почтовый сервер.
class EmailServer : public Observable
{
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

  virtual void notifyObservers(const string &message)
  {
    for (Observer *observer : observers)
      observer->update(message);
  }
};

struct Observer
{
  virtual void update(const string &message) = 0;
};

class EmailClient
{
  virtual void showMessage(const string &message) = 0;
};

class DesktopClient : public Observer, public EmailClient
{
  virtual void showMessage(const string &message)
  {
    cout << "Клиент для настольных компьютеров получил новое сообщение:" << endl;
    cout << message << endl;
  }

public:
  virtual void update(const string &message)
  {
    showMessage(message);
  }
};

struct MobileClient : public Observer, public EmailClient
{
  virtual void showMessage(const string &message)
  {
    cout << "Мобильный клиент получил новое сообщение:" << endl;
    cout << message << endl;
  }

public:
  virtual void update(const string &message)
  {
    showMessage(message);
  }
};

struct WebClient : public Observer, public EmailClient
{
  virtual void showMessage(const string &message)
  {
    cout << "Веб-клиент получил новое сообщение:" << endl;
    cout << message << endl;
  }

public:
  virtual void update(const string &message)
  {
    showMessage(message);
  }
};

int main()
{
  WebClient webClient;

  EmailServer server;
  server.addObserver(new DesktopClient());
  server.addObserver(new MobileClient());
  server.addObserver(&webClient);

  server.notifyObservers("Текст сообщения №1");

  server.removeObserver(&webClient);

  server.notifyObservers("Текст сообщения №2");

  return 0;
}