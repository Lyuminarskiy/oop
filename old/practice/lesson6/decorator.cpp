// Абстрактный компонент.
struct Component
{
    virtual void operation() = 0;
};

// Реализация компонента, в которую с помощью декоратора
// добавляется новая функциональность.
struct ConcreteComponent : public Component
{
    virtual void operation() override {}
};

// Абстрактный декоратор.
class Decorator : public Component
{
protected:
    // Декорируемый объект.
    Component *component;

public:
    void setComponent(Component *component)
    {
        this->component = component;
    }

    virtual void operation() override
    {
        if(component) component->operation();
    }
};

// Реализация декоратора, предоставляет дополнительную функциональность,
// которой должен быть расширен декорируемый объект.
struct ConcreteDecoratorA : public Decorator
{
    virtual void operation() override
    {
        Decorator::operation();
    }
};

struct ConcreteDecoratorB : public Decorator
{
    virtual void operation() override
    {
        Decorator::operation();
    }
};