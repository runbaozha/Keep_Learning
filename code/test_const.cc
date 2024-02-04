#include <iostream>

class Num {
    public:
     Num(int num) : num_(num) {}
    private:
     int num_;
};

class A {
    public:
     A(int a) : a_(a){std::cout << "construct A"<<std::endl;}
    private:
     const int a_;
};

class A1 {
    public:
     A1(){std::cout << "construct A"<<std::endl;}
     void get_num() {std::cout << num_ <<std::endl;}
    private:
     const float num_ = 1.f;
};

int main() {
    A1 a;
    a.get_num();
    return 0;
}