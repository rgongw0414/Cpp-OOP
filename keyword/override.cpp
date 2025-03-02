#include <iostream>

class Base {
public:
    void show() { std::cout << "Base::show()\n"; } // Non-Virtual function
    virtual void show_v() { std::cout << "Base::show_v()\n"; } // Virtual function
};

class Derived : public Base {
public:
    // member function declared with 'override' does not override a base class member. C/C++(1455)
    void show() override { std::cout << "Derived::show()\n"; } // Overriding a non-virtual function
    void show_v() override { std::cout << "Derived::show_v()\n"; } // Overriding function
    void show_() override { std::cout << "Derived::show_()\n"; } // Overriding a function not exist in base class
};