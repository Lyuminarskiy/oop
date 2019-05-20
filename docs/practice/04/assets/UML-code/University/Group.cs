using System;
using System.Collections.Generic;

namespace University
{
  /// <summary>
  /// Группа студентов.
  /// </summary>
  public sealed class Group : IDisplayable
  {
    /// <summary>
    /// Список студентов.
    /// </summary>
    public IList<Student> Students { get; } = new List<Student>();

    /// <inheritdoc />
    public void Display()
    {
      foreach (var student in Students)
      {
        Console.WriteLine(student.Name);
      }
    }
  }
}
