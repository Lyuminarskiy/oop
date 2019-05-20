using System;

namespace solid.srp_after
{
  interface IPrinter
  {
    void Print(string text);
  }

  class ConsolePrinter : IPrinter
  {
    public void Print(string text) =>
      Console.WriteLine(text);
  }

  class PdfPrinter : IPrinter
  {
    public void Print(string text) { /* ... */ }
  }

  class HtmlPrinter : IPrinter
  {
    public void Print(string text) { /* ... */ }
  }

  class Report
  {
    public string Text { get; set; }

    public void GoToFirstPage() =>
      Console.WriteLine("Переход к первой странице");

    public void GoToLastPage() =>
      Console.WriteLine("Переход к последней странице");

    public void GoToPage(int pageNumber) =>
      Console.WriteLine($"Переход к странице {pageNumber}");

    public void Print(IPrinter printer) =>
      printer.Print(this.Text);
  }

  class Program
  {
    static void Test()
    {
      var report = new Report
      {
        Text = "Текст отчёта"
      };

      IPrinter printer = new ConsolePrinter();
      report.Print(printer);
    }
  }
}
