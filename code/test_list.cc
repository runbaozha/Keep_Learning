#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> test_list;
    for (size_t i = 1; i < 8; ++i) {
        test_list.push_back(i*2);
    }

    std::list<int>::reverse_iterator rit = find(test_list.rbegin(), test_list.rend(), 8);
    std::list<int>::iterator it(rit.base());
    auto iter = test_list.rbegin();
    iter++;
    std::cout << *iter << std::endl;

    std::cout << *rit << std::endl;
    std::cout << *it << std::endl;
    return 0;
}