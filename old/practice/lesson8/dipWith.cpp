#include <string>

using namespace std;

// Книга.
class Book
{
  string text;

  // Зависимость от абстракции.
  Printer* printer;

public:
  Book(string text)
  {
    this->text = text;
  }

  void setPrinter(Printer* printer)
  {
    this->printer = printer;
  }

  void print()
  {
    printer->print(text);
  }
};

// Абстракция.
struct Printer
{
  virtual void print(string text) = 0;
};

// Вывод содержимого книги в консоли.
struct ConsolePrinter :  public Printer
{
  void print(string text) override {}
};

// Вывод содержимого книги в браузере.
struct HtmlPrinter :  public Printer
{
  void print(string text) override {}
}