struct Book
{
  char *text;
  ConsolePrinter* printer;

  void print()
  {
    printer->print(text);
  }
};

struct ConsolePrinter
{
  void print(char *text) {}
}