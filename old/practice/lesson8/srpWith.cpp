// Работа с заказом.
struct Order
{
  void calculateTotalSum();
  void getItems();
  void getItemCount();
  void addItem();
  void deleteItem();
};

// Отображение заказа.
struct OrderViewer
{
  void printOrder();
  void showOrder();
};

// Работа с хранилищем заказов.
struct OrderRepository
{
  void load();
  void save();
  void update();
  void del();
};