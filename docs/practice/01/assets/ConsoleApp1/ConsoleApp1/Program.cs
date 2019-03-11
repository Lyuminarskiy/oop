using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
  class Program
  {
    static void Main(string[] args)
    {
      Cat cat1 = new Cat(
        "name1", 11, Cat.Colors.Black);
      Cat cat2 = new Cat(
        "name2", 21, Cat.Colors.Green);
      Cat cat3 = new Cat(
        "name1", 11, Cat.Colors.Black);

      string str = cat1.toString();
      Console.WriteLine(str);

      cat2.name = "name3";

      Console.WriteLine(Cat.template);
      Console.WriteLine($"Age: {cat2.GetAge()}");

      bool result1 = cat1.Compare(cat3);
      Console.WriteLine(result1);

      bool result2 = Cat.Compare(cat1, cat3);
      Console.WriteLine(result2);

      bool result3 = cat1 == cat3;
      Console.WriteLine(result3);
    }
  }

  class Cat
  {
    public enum Colors
    {
      Black,
      White,
      Orange,
      Green
    }

    public string name;
    private int age;
    private Colors color;

    public const string template =
      "Name: {0}\nAge: {1}";

    public int GetAge()
    {
      return age;
    }

    public Cat(string name, int age, Colors color)
    {
      this.name = name;
      this.age = age;
      this.color = color;
    }

    public string toString()
    {
      return string.Format(template, name, age);
    }

    public bool Compare(Cat another)
    {
      return name == another.name &&
             age == another.age &&
             color == another.color;
    }

    public static bool Compare(Cat first, Cat second)
    {
      return first.Compare(second);
    }

    public static bool operator ==(Cat first, Cat second)
    {
      return first.Compare(second);
    }

    public static bool operator !=(Cat first, Cat second)
    {
      return !first.Compare(second);
    }
  }
}
