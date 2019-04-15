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
    public List<Group> Groups { get; set; } = new List<Group>();

    /// <summary>
    /// Создаёт экземпляр класса <see cref="Teacher"/>.
    /// </summary>
    /// <param name="name">Имя преподавателя.</param>
    public Teacher(string name) : base(name) { }
  }
}
