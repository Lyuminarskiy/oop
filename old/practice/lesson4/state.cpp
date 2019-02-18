struct State
{
  virtual void handle(Context *context) = 0;
};

struct StateA : public State
{
  virtual void handle(Context *context)
  {
    context->state = new StateB();
  }
};

struct StateB : public State
{
  virtual void handle(Context *context)
  {
    context->state = new StateA();
  }
};

// Объект, поведение которого должно динамически
// изменяться в соответствии с состоянием.
struct Context
{
  State *state;

  Context(State *state)
  {
    this->state = state;
  }

  void request()
  {
    this->state->handle(this);
  }
};

int main()
{
  Context context(new StateA());

  context.request(); // Переход в состояние StateB
  context.request(); // Переход в состояние StateA

  return 0;
}