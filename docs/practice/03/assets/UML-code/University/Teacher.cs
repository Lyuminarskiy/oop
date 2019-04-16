using System.Collections.Generic;

namespace University
{
  /// <summary>
  /// Преподаватель.
  /// </summary>
  public sealed class Teacher : Person
  {
    /// <summary>
    /// Группы преподавателя.
    /// </summary>
    public IList<Group> Groups { get; set; } = new List<Group>();

    /// <summary>
    /// Создаёт экземпляр класса <see cref="Teacher"/>.
    /// </summary>
    /// <param name="name">Имя преподавателя.</param>
    /// <param name="gender">Пол преподавателя.</param>
    public Teacher(string name, Gender gender) : base(name, gender) { }
  }
}
