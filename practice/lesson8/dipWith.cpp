struct Book
{
  char *text;
  Printer* printer;

  void print()
  {
    printer->print(text);
  }
};

struct Printer
{
  virtual void print(char *text) = 0;
};

struct ConsolePrinter :  public Printer
{
  void print(char *text) override {}
}

struct HtmlPrinter :  public Printer
{
  void print(char *text) override {}
}