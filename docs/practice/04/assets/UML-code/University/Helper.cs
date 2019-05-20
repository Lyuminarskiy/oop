using System;
using System.Linq;

namespace University
{
  /// <summary>
  /// Вспомогательный класс.
  /// </summary>
  public static class Helper
  {
    public static void ShowTeacherInfo(Teacher teacher)
    {
      Console.WriteLine(teacher.Name);

      foreach (var group in teacher.Groups)
      {
        group.Display();
      }
    }
  }
}
