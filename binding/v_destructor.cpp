#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base class constructor" << std::endl;
    }
    virtual ~Base() = 0; // Pure virtual destructor
};

Base::~Base() {
    //-----------------------------------------------------
    /* Unlike simple/pure virtual functions, pure virtual ***DESTRUCTORS*** must have a definition in the base class, even if it is pure.
    This is mainly because of the v_table mechanism: The v_table contains the addresses of the virtual functions of the class.
    Secondly, automatically, the derived class destructor will call the base class destructor, and if the base class destructor is not defined,
    the derived class destructor will not be able to call it through the virtual table of base_obj. */
   //-----------------------------------------------------
    std::cout << "Base class destructor" << std::endl;
}

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived class destructor" << std::endl; // Implementation in Derived class destructor
    }
    void someFunction() {
        std::cout << "Function in Derived class" << std::endl;
    }
};
    
int main() {
    Base* basePtr = new Derived(); // created on the heap, i.e., it is created at runtime.
    delete basePtr;
    return 0;
}