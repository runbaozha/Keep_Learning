#include <iostream>

void func() {
    static int a = 0;
    ++a;
    std::cout << "a:" <<a<< std::endl;
} 

int main() {
    func();
    func();
    func();
}