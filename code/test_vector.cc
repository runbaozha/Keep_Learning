#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec(10,1);
    std::cout << vec.capacity() << ","<< vec.size()<<std::endl;
    vec.push_back(3);
    std::cout << vec.capacity() << ","<< vec.size()<<std::endl;
    vec.reserve(100);
    std::cout << vec.capacity() << ","<< vec.size()<<std::endl;

    vec.resize(200);
    std::cout << vec.capacity() << ","<< vec.size()<<std::endl;

    int a = 0, c = 1;
    int& aa = a;
    aa = c;
    std::cout << aa <<std::endl;
    std::cout << c <<std::endl;

    std::vector<int>().swap(vec);
    std::cout << vec.capacity() << ","<< vec.size()<<std::endl;
    return 0;
}