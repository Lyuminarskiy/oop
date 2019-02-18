#include <string>

using namespace std;

// Книга
class Book
{
  string text;

  // Зависимость от класса.
  ConsolePrinter printer;

public:
  Book(string text)
  {
    this->text = text;
  }

  void print()
  {
    printer.print(text);
  }
};

// Вывод содержимого книги в консоли.
struct ConsolePrinter
{
  void print(string text) {}
}