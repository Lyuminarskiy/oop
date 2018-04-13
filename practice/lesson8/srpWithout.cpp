// Заказ.
struct Order
{
  // Работа с заказом.
  void calculateTotalSum();
  void getItems();
  void getItemCount();
  void addItem();
  void deleteItem();

  // Отображение заказа.
  void printOrder();
  void showOrder();

  // Работа с хранилищем заказов.
  void load();
  void save();
  void update();
  void del();
}