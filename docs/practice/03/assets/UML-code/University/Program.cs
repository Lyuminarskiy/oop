using System;

namespace University
{
  public static class Program
  {
    public static void Main(string[] args)
    {
      var teacher = new Teacher("teacher#1")
      {
        Gender = Gender.Male,
        Groups =
        {
          new Group()
          {
            Students =
            {
              new Student("student#1"),
              new Student("student#2"),
              new Student("student#3")
            }
          },
          new Group()
          {
            Students =
            {
              new Student("student#3"),
              new Student("student#4"),
              new Student("student#5")
            }
          }
        }
      };
      
      Helper.ShowTeacherInfo(teacher);
    }
  }
}
