using System;

namespace solid.srp_before
{
  class Book
  {
    public string Text { get; set; }
    public void GoToFirstPage()
    {
      Console.WriteLine("Переход к первой странице");
    }

    public void GoToLastPage()
    {
      Console.WriteLine("Переход к последней странице");
    }

    public void GoToPage(int pageNumber)
    {
      Console.WriteLine("Переход к странице {0}", pageNumber);
    }

    public void Print()
    {
      Console.WriteLine("Печать отчета");
      Console.WriteLine(Text);
    }
  }

  class Program
  {
    static void Test()
    {
      var report = new Book
      {
        Text = "Текст отчёта"
      };

      report.Print();
    }
  }
}
