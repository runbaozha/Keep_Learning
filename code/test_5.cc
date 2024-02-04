#include <iostream>

class MyInt {
 public:
  explicit MyInt(int n) : num(n) {};
//   private:
  int num;
};


int main() {
    MyInt a = MyInt(10);
    std::cout << a.num << std::endl;
    return 0;
}
