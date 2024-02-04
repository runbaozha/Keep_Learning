#include <iostream>

int main() {
    int a = 10;
    // auto f = [a]() {
    //     return ++a;
    // };

    // 
    auto f = [a]() mutable {
        return ++a;
    };
    std::cout << f() <<std::endl;
    std::cout << f() <<std::endl;
    std::cout << a <<std::endl;
    return 0;
}