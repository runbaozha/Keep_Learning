#include <iostream>

class A {
    public:
        A(int in) : num(in) {}
        int func1() const { return num;}
        int func1() {return num+1;}
    private:
        int num;
};

int main() {
    const A a(10);
    int num1 = a.func1();
    std::cout << num1 << std::endl;
    return 0;
}