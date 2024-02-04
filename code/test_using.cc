#include <iostream>

class Base {
    public:
        void dosomething() {
            std::cout << "This is Base::dosomthing. " << std::endl;
        }
    protected:
        int value;
};

class Derived1 : private Base {
    public:
        using Base::dosomething;
        using Base::value;
};

class Derived2 : public Base {
    public:
        using Base::dosomething;
        void dosomething(int num) {std::cout << "This is Derived2::dosomething, the arg is: " << num << std::endl;}
};


int main() {
    Derived1 d1;
    d1.dosomething();
    std::cout << "d.value: " << d1.value << std::endl;

    Derived2 d2;
    d2.dosomething();
    d2.dosomething(2);
    
    return 0;
}