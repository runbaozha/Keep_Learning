#include <iostream>

class A {
  public:
    static int b;
    static void func() {std::cout << "func" << std::endl;}
    // static void func1() {std::cout << "a: " << a << std::endl;}
    static void func2() {std::cout << "b: " << b << std::endl;}
  private:
    int a;
    
};
int A::b = 1;

int main() {
    
    A::func();
    A::func2();
    return 0;
}