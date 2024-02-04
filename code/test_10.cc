#include <iostream>
#include <string>

class Window {
  public:
    virtual ~Window() {std::cout << "Window deconstruct!" << std::endl;}
    virtual void display() const {
      static int a = 0;
      a++;
      std::cout << "Window: " << a << std::endl;
    }
};

class MyWindow : public Window {
  public:
    virtual ~MyWindow() {std::cout << "MyWindow deconstruct!" << std::endl;}
    void display() const override {
      std::cout << "My Window" << std::endl;
    }
};

void displayname (Window w) {
  w.display();

}
int main() {
  Window w;
  displayname(w);
  displayname(w);
  return 0;
}