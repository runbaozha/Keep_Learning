#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

auto main() ->int {
    std::vector vec {1, 2, 3};
    std::ranges::for_each(std::views::reverse(vec), [](const auto& e){ std::cout << e << " ";} );
}