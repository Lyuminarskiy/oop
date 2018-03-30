// Компонент системы.
struct ComponentA
{
    void operationA1() {}
    void operationA2() {}
};

// Компонент системы.
struct ComponentB
{
    void operationB1() {}
    void operationB2() {}
};

// Компонент системы.
struct ComponentC
{
    void operationC1() {}
    void operationC2() {}
};

// Фасад, предоставляет единую точку для работы с компонентами.
class Facade
{
    ComponentA *componentA;
    ComponentB *componentB;
    ComponentC *componentC;

public:
    Facade(ComponentA *componentA,
           ComponentB *componentB,
           ComponentC *componentC) : 
             componentA(componentA),
             componentB(componentB),
             componentC(componentC) {}

    void operation1()
    {
        componentA->operationA1();
        componentB->operationB1();
        componentB->operationB2();
    }

    void operation2()
    {
        componentA->operationA2();
        componentB->operationB1();
        componentC->operationC1();
        componentC->operationC2();
    }
};

void main()
{
    Facade facade(new ComponentA(), new ComponentB(), new ComponentC());
    facade.operation1();
    facade.operation2();
}