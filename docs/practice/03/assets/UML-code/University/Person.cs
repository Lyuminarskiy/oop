using System;

namespace University
{
  /// <summary>
  /// Личность.
  /// </summary>
  public abstract class Person : IDisplayable
  {
    /// <summary>
    /// Пол личности.
    /// </summary>
    public Gender Gender;

    /// <summary>
    /// Имя личности.
    /// </summary>
    public string Name { get; set; }

    /// <inheritdoc />
    public void Display()
    {
      Console.WriteLine(Name);
    }

    /// <summary>
    /// Создаёт экземпляр класса <see cref="Person"/>.
    /// </summary>
    /// <param name="name">Имя личности.</param>
    /// <param name="gender">Пол личности.</param>
    protected Person(string name, Gender gender)
    {
      Name = name;
      Gender = gender;
    }
  }
}
