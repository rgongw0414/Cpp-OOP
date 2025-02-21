#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base class constructor" << std::endl;
    }
    virtual ~Base() = 0; // Pure virtual destructor
};

Base::~Base() {
    // Implementation of pure virtual destructor
    std::cout << "Base class destructor" << std::endl;
}

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived class destructor" << std::endl; // Add implementation to Derived class destructor
    }
    void someFunction() {
        std::cout << "Function in Derived class" << std::endl;
    }
};
    
int main() {
    Base* basePtr = new Derived();
    delete basePtr;
    return 0;
}