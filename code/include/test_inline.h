#include <utility>
#include <iostream>
inline int myAdd(int a, int b) {
    return a + b;
}

template <typename T, bool = std::is_same_v<T, int>>
class A {
public:

void print();

};

template <typename T, bool isInteger>
void A<T, isInteger>::print() {
    std::cout <<  " i dont know\n";
}

template<typename T>
class A<T, true> {
public:
    void print() {
        std::cout << "this is true\n";
    }
};

class B {
public:
void print();
};

inline void B::print() {

    std::cout << "this is B\n";
}