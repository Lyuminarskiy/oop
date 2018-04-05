#include <list>

using namespace std;

// Общий интерфейс для всех компонентов в древовидной структуре.
struct Component
{
  virtual void operation() = 0;
  virtual void add(Component*) {};
  virtual void remove(Component*) {};
};

// Отдельный компонент, не может содержать другие компоненты.
struct Leaf : public Component
{
  virtual void operation() override {};
};

// Компонент, который может содержать другие компоненты.
class Composite : public Component
{
  // Список вложенных компонентов.
  list<Component*> components;

public:
  virtual void operation() override {};

  virtual void add(Component* component) override
  {
    components.push_back(component);
  };

  virtual void remove(Component* component) override
  {
    components.remove(component);
  };
};

int main()
{
  Composite root;
  Leaf sub1;
  Leaf sub2;

  sub1.operation();
  sub2.operation();
  root.operation();

  root.add(&sub1);
  root.add(&sub2);

  return 0;
}