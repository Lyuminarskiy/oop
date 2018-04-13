// Абстрактное хранилище.
struct OrderSource
{
  virtual void load() = 0;
  virtual void save() = 0;
  virtual void update() = 0;
  virtual void del() = 0;
};

// Хранилище в виде СУБД MySQL.
struct MysqlOrderSource : public OrderSource
{
  virtual void load();
  virtual void save();
  virtual void update();
  virtual void del();
};

// Хранилище в виде СУБД SQLite.
struct SqliteOrderSource : public OrderSource
{
  virtual void load();
  virtual void save();
  virtual void update();
  virtual void del();
};

// Работа с хранилищем заказов.
class OrderRepository
{
  OrderSource* orderSource;

public:
  // Позволяет изменить тип хранилища.
  void setSource(OrderSource* orderSource);

  void load();
  void save();
  void update();
  void del();
};