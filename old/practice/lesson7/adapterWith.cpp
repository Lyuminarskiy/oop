// Классы, поставляемые разработчиком СУБД.
class MysqlApi {};
class PostgresqlApi {};
class SqliteApi {};

// Общий интерфейс для всех СУБД.
struct SqlAdapter
{
  virtual void connect() = 0;
  virtual void disconnect() = 0;

  virtual void create(int id) = 0;
  virtual void read(int id) = 0;
  virtual void update(int id) = 0;
  virtual void del(int id) = 0;
};

// Адаптер для MySQL API.
class MysqlAdapter : public SqlAdapter
{
  MysqlApi mysqlApi;

public:
  virtual void connect() override {};
  virtual void disconnect() override {};

  virtual void create(int id) override {};
  virtual void read(int id) override {};
  virtual void update(int id) override {};
  virtual void del(int id) override {};
};

// Адаптер для PostgreSQL API.
class PostgresqlAdapter : public SqlAdapter
{
  PostgresqlApi postgresqlApi;

public:
  virtual void connect() override {};
  virtual void disconnect() override {};

  virtual void create(int id) override {};
  virtual void read(int id) override {};
  virtual void update(int id) override {};
  virtual void del(int id) override {};
};

// Адаптер для SQLite API.
class SqliteAdapter : public SqlAdapter
{
  SqliteApi sqliteApi;

public:
  virtual void connect() override {};
  virtual void disconnect() override {};

  virtual void create(int id) override {};
  virtual void read(int id) override {};
  virtual void update(int id) override {};
  virtual void del(int id) override {};
};

void main()
{
  // Выбираем нужный адаптер в зависимости от СУБД.
  SqlAdapter* db = new MysqlAdapter();

  // Работаем через единый интерфейс с любыми СУБД.
  db->connect();
  {
    db->create(1);

    db->read(3);
    db->update(3);

    db->del(4);
  }
  db->disconnect();
}