// Синглтон Майерса.
class Singleton
{
public:
  static Singleton &Instance()
  {
    static Singleton instance;
    return instance;
  }

private:
  // Убираем возможность создания экземпляров класса.
  Singleton(){};
  Singleton(const Singleton &root) = delete;
  Singleton &operator=(const Singleton &) = delete;
};