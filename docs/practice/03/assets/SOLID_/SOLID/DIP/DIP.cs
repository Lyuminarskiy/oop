#define DIP
// The Dependency Inversion Principle - принцип инверсии зависимостей

namespace SOLID.DIP
{
#if DIP
  #region With DIP
  /// <summary>
  /// База данных пользователей.
  /// </summary>
  public interface IUserDatabase
  {
    /// <summary>
    /// Загружает пользователя с указанным именем из базы данных.
    /// </summary>
    /// <param name="name">Имя пользователя.</param>
    /// <returns>Пользователь.</returns>
    User LoadUser(string name);

    /// <summary>
    /// Сохраняет пользователя в базе данных.
    /// </summary>
    /// <param name="user">Пользователь.</param>
    void SaveUser(User user);
  }

  /// <summary>
  /// Пользователь.
  /// </summary>
  public class User
  {
    /// <summary>
    /// База данных пользователей.
    /// </summary>
    private readonly IUserDatabase _db;

    /// <summary>
    /// Имя пользователя.
    /// </summary>
    public string Name { get; set; }

    /// <summary>
    /// Создаёт экземпляр класса <see cref="User"/>.
    /// </summary>
    /// <param name="name">Имя пользователя.</param>
    /// <param name="db">База данных пользователей.</param>
    public User(string name, IUserDatabase db = null)
    {
      Name = name;
      _db = db;
    }
  }

  /// <summary>
  /// База данных пользователей.
  /// </summary>
  public class UserDatabase : IUserDatabase
  {
    /// <summary>
    /// Загружает пользователя с указанным именем из базы данных.
    /// </summary>
    /// <param name="name">Имя пользователя.</param>
    /// <returns>Пользователь.</returns>
    public User LoadUser(string name) => new User(name);

    /// <summary>
    /// Сохраняет пользователя в базе данных.
    /// </summary>
    /// <param name="user">Пользователь.</param>
    public void SaveUser(User user) { }
  }
  #endregion
#else
  #region Without DIP/// <summary>
  /// <summary>
  /// Пользователь.
  /// </summary>
  public class User
  {
    private readonly UserDatabase _db = new UserDatabase();

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
  public class UserDatabase
  {
    /// <summary>
    /// Загружает пользователя с указанным именем из базы данных.
    /// </summary>
    /// <param name="name">Имя пользователя.</param>
    /// <returns>Пользователь.</returns>
    public User LoadUser(string name) => new User(name);

    /// <summary>
    /// Сохраняет пользователя в базе данных.
    /// </summary>
    /// <param name="user">Пользователь.</param>
    public void SaveUser(User user) { }
  }
  #endregion
#endif
}
