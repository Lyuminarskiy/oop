#define SRP
// The Single Responsibility Principle - принцип единственной ответственности

namespace SOLID.SRP
{
#if SRP
  #region With SRP
  /// <summary>
  /// Пользователь.
  /// </summary>
  public abstract class User
  {
    /// <summary>
    /// Имя пользователя.
    /// </summary>
    public string Name { get; set; }

    /// <summary>
    /// Создаёт экземпляр класса <see cref="User"/>.
    /// </summary>
    /// <param name="name">Имя пользователя.</param>
    public User(string name) => Name = name;
  }

  /// <summary>
  /// База данных пользователей.
  /// </summary>
  public abstract class UserDatabase
  {
    /// <summary>
    /// Загружает пользователя с указанным именем из базы данных.
    /// </summary>
    /// <param name="name">Имя пользователя.</param>
    /// <returns>Пользователь.</returns>
    public abstract User LoadUser(string name);

    /// <summary>
    /// Сохраняет пользователя в базе данных.
    /// </summary>
    /// <param name="user">Пользователь.</param>
    public abstract void SaveUser(User user);
  }
  #endregion
#else
  #region Without SRP
  /// <summary>
  /// Пользователь.
  /// </summary>
  public abstract class User
  {
    /// <summary>
    /// Имя пользователя.
    /// </summary>
    public string Name { get; set; }

    /// <summary>
    /// Создаёт экземпляр класса <see cref="User"/>.
    /// </summary>
    /// <param name="name">Имя пользователя.</param>
    public User(string name) => Name = name;

    /// <summary>
    /// Загружает пользователя с указанным именем из базы данных.
    /// </summary>
    /// <param name="name">Имя пользователя.</param>
    /// <returns>Пользователь.</returns>
    public abstract User LoadUser(string name);

    /// <summary>
    /// Сохраняет пользователя в базе данных.
    /// </summary>
    /// <param name="user">Пользователь.</param>
    public abstract void SaveUser(User user);
  }
  #endregion
#endif
}
