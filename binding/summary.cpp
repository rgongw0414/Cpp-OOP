#include <iostream>

class Base {
public:
    virtual void show() { std::cout << "Base::show()\n"; } // Virtual function
    virtual void show2() { std::cout << "Base::show2()\n"; } // Virtual function
    void nv_func() { std::cout << "Base::nv_func()\n"; } // Non-Virtual function
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived::show()\n"; } // Overriding function
    void show2() override { std::cout << "Derived::show2()\n"; } // Overriding function
};

int main() {
    Derived d;
    Base* ptr = &d; // Upcasting
    ptr->nv_func(); // Calls Base::func() (static binding)
    ptr->show();    // Calls Derived::show() dynamically
    ptr->show2();   // Calls Derived::show() dynamically
    return 0;
}
