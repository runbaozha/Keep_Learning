#include <iostream>

class A {
    public:
        virtual void func();
};

class B : public virtual A {
    public:
        virtual void foo1();
};

class C : public virtual A {
    public:
        virtual void foo2();
};

class D : public B, public C {
    public:
    virtual void foo3();
};

class a {
    virtual void func();
    char x;
};

int main() {
    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;
    std::cout << sizeof(C) << std::endl;
    std::cout << sizeof(D) << std::endl;
    std::cout << sizeof(a) << std::endl;


    return 0;
}