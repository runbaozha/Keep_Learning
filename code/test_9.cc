#include <iostream>
#include <cstring>

// struct A {
//     bool n;
//     int m[4];
//     A () {
//         memset(this, 0, sizeof(A));
//     };

// };
struct B {
    bool m[9];
    int bb[5];
    
};

class A {
    public:
    B n;
    bool m[5];
    A () {
        memset(this, 0, sizeof(A));
    }
    void printsize () {std::cout << sizeof(A) << std::endl;}
    virtual ~A() = 0;

};

A::~A() {
    std::cout << "A deconstruted!" << std::endl;
};

class Derived_A : public A {
    public:
    ~Derived_A() {
        std::cout << "Derived A!" << std::endl;
    }
};

int main() {
    Derived_A a;
    std::cout << std::hex << a.m << std::endl;
    for (int i = 0; i < 6;i++) {
        std::cout << std::dec << a.m[i] << ",";
    }
    std::cout << std::endl;
    // std::cout << a.m[3] << std::endl;
    a.printsize();
}