#include <memory>
#include <iostream>

class MyClass {
  public:
   MyClass() {std::cout << "constructed!"<<std::endl;};
   ~MyClass() {std::cout << "deconstructed!"<< std::endl;};
};

int main() {
  {
    std::shared_ptr<MyClass> shared_ptr = std::make_shared<MyClass>();
  }
  return 0;

}