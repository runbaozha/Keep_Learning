#include <utility> // std::is_same_v
#include <type_traits>
#include <iostream>
#include "include/test_inline.h"

namespace my {
    template <typename T, typename = std::enable_if_t<std::is_same_v<T, int>>>
    T add(const T a, const T b) {
        return a + b;
    }
}

int other();

auto main() -> int {
//  float a = 10, b = 20;
// //  auto c = my::add(a, b);
//  std::cout << "c: " << myAdd(a, b) << std::endl;
//  std::cout << other() << std::endl;
 A<int> a;
 a.print();
 A<float> b;
 b.print();
 other();
 return 0;
}