#include <cstdio>

class Human {
  public:
    char* name = "name";
    int age = 33;

    virtual void toString();
}

class Mom {
  public:
    virtual void toString() {
      printf("Мама");
    }
};

class Dad {
  public:
    virtual void toString() {
      printf("Папа");
    }
};

class Child : Mom, Dad {
  public:
    Child() {
      name = "other";
      age = 27;
    }

    virtual void toString() {
      Dad::toString();
    }
};

void main() {
  Child child();
  child.toString();

  ((Mom)child).toString();
  ((Dad)child).toString();
}