#include <iostream>
#include <mutex>
#include <memory>

using namespace std;

template<typename T>
class SimpleSharedPtr {
  public:
  // 构造函数
    explicit SimpleSharedPtr(T* ptr = nullptr): ptr_(ptr), count_(ptr ? new size_t(1): nullptr) {};
    
  // 拷贝构造函数
    SimpleSharedPtr(SimpleSharedPtr &other) : ptr_(other.ptr_), count_(other.count_) {
      if (count_) {
        ++(*count_);
      }
    }
  // 赋值操作符
   SimpleSharedPtr& operator=(const SimpleSharedPtr &other) {
    if (this != &other) {
      release();
      ptr_= other.ptr_;
      count_ = other.count_;
      if (count_) {
        ++(*count_);
      }
    }
    return *this;
   }

   // 析构
   ~SimpleSharedPtr() {
    release();
   }

   T& operator*() const {return *ptr_;}
   T* operator->() const {return ptr_;}
   T* get() const {return ptr_;}
   size_t use_count() const {return count_ ? *count_ : 0;}

  private:
    void release() {
      if (count_ && --(*count_) == 0) {
        delete ptr_;
        delete count_;
      }
    }
    T* ptr_;
    size_t* count_;
};

class MyClass {
  public:
  MyClass() {std::cout << "constructed!"<< endl;}
  ~MyClass() {std::cout << "deconstructed!"<< endl;}
  void domesomething() {
    std::cout << "dosomething"<<endl;
  }

};

class MyLock {
  public:
    explicit MyLock(std::mutex& mtx) : mutex_(mtx) {
      mutex_.lock();
    }
    ~MyLock() {
      mutex_.unlock();
    }

    MyLock(const MyLock& other) = delete;
    MyLock& operator=(const MyLock&) = delete;
  private:
    std::mutex &mutex_;
};

int main() {
  
  // SimpleSharedPtr<MyClass> sptr1(new MyClass());
  // {
  //   SimpleSharedPtr<MyClass> sptr2(sptr1);
  //   sptr1->domesomething();
  //   sptr2->domesomething();
  //   std::cout << "引用计数: " << sptr1.use_count() << endl; 
  // }
  // std::cout << "引用计数: " << sptr1.use_count() << endl;
  std::mutex mtx;
  {
    MyLock lck(mtx);
  }
  return 0;
}