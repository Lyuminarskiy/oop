// Работа с хранилищем заказов.
// Тип хранилища нельзя изменить.
struct OrderRepository
{
  void load();
  void save();
  void update();
  void del();
};