using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
  class Program
  {
    static void Main(string[] args)
    {
      Cat cat = new Cat(
        "cat", Animal.Colors.WHITE, 7);
      Dog dog = new Dog(
        "dog", Animal.Colors.BROWN, 9);
      
      Display(cat);
      Display(dog);

      Animal animal = dog;

      IMyInterface1 cat2 = new SpecialCat(
        "cat", Animal.Colors.WHITE, 7);
      IMyInterface2 cat3 = new SpecialCat(
        "cat", Animal.Colors.WHITE, 7);

      cat2.DoSomethingSpecial();
      cat3.DoSomethingSpecial();

      int a = 1, b = 2;
      Swap<int>(ref a, ref b);

      string c = "sdf", d = "efg";
      Swap<string>(ref c, ref d);

      List<int> list1 = new List<int>();
      List<string> list2 = new List<string>();
    }

    static void Display(Animal animal)
    {
      string result = animal.toString();
      Console.WriteLine(result);

      animal.DoSomething();
    }

    //static void Swap(ref int first, ref int second)
    //{
    //  int temp = first;
    //  first = second;
    //  second = temp;
    //}

    //static void Swap(ref string first, ref string second)
    //{
    //  string temp = first;
    //  first = second;
    //  second = temp;
    //}

    static void Swap<T>(ref T first, ref T second)
    {
      T temp = first;
      first = second;
      second = temp;
    }
  }

  abstract class Animal
  {
    public enum Colors
    {
      BLACK,
      WHITE,
      BROWN
    }

    public string name;
    protected int age;
    protected Colors color;

    public int GetAge()
    {
      return age;
    }
    public Colors GetColor()
    {
      return color;
    }
    public Animal(string name, Colors color) :
      this(name, color, 0)
    { }

    public Animal(
      string name, Colors color, int age)
    {
      this.name = name;
      this.color = color;
      this.age = age;
    }


    public bool Compare(Animal another)
    {
      return name == another.name &&
             age == another.age &&
             color == another.color;
    }

    public static bool Compare(
      Animal first, Animal second)
    {
      return first.Compare(second);
    }

    public static bool operator ==(
      Animal first, Animal second)
    {
      return first.Compare(second);
    }

    public static bool operator !=(
      Animal first, Animal second)
    {
      return !first.Compare(second);
    }

    public const string template =
      "Имя: {0}\nВозраст: {1}\n";

    public virtual string toString()
    {
      return string.Format(
        template, name, age);
    }

    public abstract void DoSomething();
  }

  class Cat : Animal
  {
    public Cat(
      string name, Animal.Colors color, int age) :
      base(name, color, age)
    {
      Console.WriteLine("Кошка готова");
    }

    public override void DoSomething()
    {
      Console.WriteLine("Привет от кошки");
    }

    public override string toString()
    {
      return "Кошка\n" + string.Format(
        template, name, age);
    }
  }

  class Dog : Animal
  {
    public Dog(
      string name, Animal.Colors color, int age) :
      base(name, color, age)
    {
      Console.WriteLine("Собака готова");
    }

    public override void DoSomething()
    {
      Console.WriteLine("Привет от кошки");
    }

    public override string toString()
    {
      return "Собака\n" + string.Format(
               template, name, age);
    }
  }

  interface IMyInterface1
  {
    void DoSomethingSpecial();
  }
  interface IMyInterface2
  {
    void DoSomethingSpecial();
  }

  class SpecialCat : Cat, IMyInterface1, IMyInterface2
  {
    public SpecialCat(
      string name, Animal.Colors color, int age) :
      base(name, color, age)
    { }

    public void DoSomethingSpecial()
    {
      Console.WriteLine("0");
    }

    //void IMyInterface1.DoSomethingSpecial()
    //{
    //  Console.WriteLine("1");
    //}

    //void IMyInterface2.DoSomethingSpecial()
    //{
    //  Console.WriteLine("2");
    //}
  }
}
