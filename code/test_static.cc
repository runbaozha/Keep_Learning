#include <iostream>

class A {
    public:
        A() {std::cout << "construct A" << std::endl;}
};

// class B {
//     public:
//         B(int num) : num_(num){std::cout << "construct B" << std::endl;}
//     private:
//         static int num_;
// };

// class B1 {
//     public:
//         B1(int num) {
//             num_ = num;
//             std::cout << "construct B1" << std::endl;}
//     private:
//         static int num_;
// };

class B2 {
    public:
        B2(int num){std::cout << "construct B" << std::endl;}
    private:
        const static int num_ = 1;
};

class B3 {
    public:
        B2(int num){std::cout << "construct B" << std::endl;}
    private:
        static int num_ = 1;
};

static A a1;
A a2;
const A a6;


void func() {
    static A a3;
}

int main() {
    std::cout << "------main-------" << std::endl;
    static A a4;
    std::cout << "-----------" << std::endl;
    func();
    std::cout << ",,,,,,,,,,,,,,," << std::endl;
    // const A a5;
    int b = 5;
    {
        static int bb = b;
    }
    B3 bb(1);
    return 0;
}