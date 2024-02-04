#include <iostream>

class Base {
  public:
    virtual void  display() {
        std::cout << "base" <<std::endl;
    }
};

class Derived : public Base {
  public:
    void display() override {
        std::cout << "derived" << std::endl;
    }
};

int main() {
    Derived derived;
    derived.display();
    return 0;
}