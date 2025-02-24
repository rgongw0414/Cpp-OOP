#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function (static binding)" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function (dynamic binding)" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    Base* basePtr = &derivedObj;
    basePtr->show();      // Calls Derived::show() - Dynamic Binding (Base pointer)
    
    return 0;
}
