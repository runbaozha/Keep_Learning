#include <iostream>

// global init
int func() {
    std::cout << "func" << std::endl;
    return 1;
}

int a = func();

// lambda 
int b = []() {
    std::cout << "lambda" <<std::endl;
    return 0;
}();

int main() {
    std::cout << "-------main---------" <<std::endl;
    return 0;
}