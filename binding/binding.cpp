#include <iostream>

class Base {
public:
    void show() {
        std::cout << "Base class show function (static binding)" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() {
        std::cout << "Derived class show function (static binding)" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    baseObj.show();       // Calls Base::show() - Static Binding
    derivedObj.show();    // Calls Derived::show() - Static Binding

    Base* basePtr = &derivedObj;
    basePtr->show();      // Calls Base::show() - Static Binding (Base pointer)
    
    return 0;
}
