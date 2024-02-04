#include <iostream>
#include <vector>

int main() {
    std::vector<int> sourceVector = {1, 2, 3, 4, 5};
    std::vector<int> targetVector = {6, 7, 8, 9, 10};

    // 使用assign函数将sourceVector的前3个元素赋值给targetVector的前3个元素
    targetVector.assign(sourceVector.begin(), sourceVector.begin() + 3);

    // 输出targetVector的内容
    for (int value : targetVector) {
        std::cout << value << " ";
    }

    return 0;
}
