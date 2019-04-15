using System;

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
      teacher.Groups.ForEach(group => group.Display());
    }
  }
}
