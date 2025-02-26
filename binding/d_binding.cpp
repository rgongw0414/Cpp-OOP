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
    Derived derivedObj;
    Base* basePtr = &derivedObj;
    // the implementation of show() to be called is determined at runtime (by looking up the vtable)
    basePtr->show();      // Calls Derived::show() - Dynamic Binding (Base pointer)

    /* To achieve dynamic binding (through vtable) these are the steps:
     * 1. Create a pointer to the object of the base class
     * 2. Assign the address of the derived class object to the base class pointer
     *     i.e., Base* basePtr = &derivedObj;
     * 3. Call the function using the base class pointer: basePtr->show();
     * 4. The implementation of the function to be called is determined at runtime (by looking up the vtable)
    */
    
    return 0;
}
