#include <iostream>

class Widge {
  public:
    explicit Widge(int a) {std::cout << "Widge constructed!" << std::endl;}
};

void dosomething(const Widge& widge) {
  
}

int main() {
  // dosomething(Widge(15));
  dosomething(static_cast<Widge>(15));
  return 0;
}