namespace University
{
  /// <summary>
  /// Студент.
  /// </summary>
  public sealed class Student : Person
  { 
    /// <summary>
    /// Группа студента.
    /// </summary>
    public Group Group { get; set; }

    /// <summary>
    /// Создаёт экземпляр класса <see cref="Student"/>.
    /// </summary>
    /// <param name="name">Имя студента.</param>
    /// <param name="gender">Пол студента.</param>
    public Student(string name, Gender gender) : base(name, gender) { }
  }
}
