// Товар.
struct Item
{
  virtual void setCondition() = 0;
  virtual void setPrice() = 0;
};

// Внешний вид товара.
struct Look
{
  virtual void setColor() = 0;
  virtual void setSize() = 0;
  virtual void setMaterial() = 0;
};

// Скидка на товар.
struct Discount
{
  virtual void applyDiscount() = 0;
  virtual void applyPromocode() = 0;
};

class Book : public Item, public Discount {};
class Clothes : public Item, public Look {};