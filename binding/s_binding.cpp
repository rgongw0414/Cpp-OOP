#include <iostream>

class Base {
public:
    void show() {
        std::cout << "Base class show function (static binding)" << std::endl;
    }
    int x = 100;
};

class Derived : public Base {
public:
    void show() {
        std::cout << "Derived class show function (static binding)" << std::endl;
    }
    int y = 200;
};

int main() {
    Base baseObj;
    Derived derivedObj;

    Base* basePtr = &derivedObj;
    basePtr->show();      // Calls Base::show() called - Static Binding (Base pointer), because it is not virtual
    std::cout << basePtr->x << std::endl;
    // cout << basePtr->y << endl; // Error: 'class Base' has no member named 'y', it is not accessible through basePtr

    Derived* derivedPtr = &derivedObj;
    std::cout << derivedPtr->y << std::endl;
    derivedObj.show();    // Calls Derived::show() - Static Binding (Derived object), the class of the object is known at compile time
    
    return 0;
}