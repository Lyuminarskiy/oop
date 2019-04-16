using System;

namespace University
{
  public static class Program
  {
    public static void Main(string[] args)
    {
      var teacher = new Teacher("teacher#1", Gender.Male)
      {
        Groups =
        {
          new Group()
          {
            Students =
            {
              new Student("student#1", Gender.Male),
              new Student("student#2", Gender.Male),
              new Student("student#3", Gender.Male)
            }
          },
          new Group()
          {
            Students =
            {
              new Student("student#3", Gender.Female),
              new Student("student#4", Gender.Female),
              new Student("student#5", Gender.Female)
            }
          }
        }
      };
      
      Helper.ShowTeacherInfo(teacher);
    }
  }
}
