#include <iostream>

// The final keyword is used to prevent a class from being inherited.
class Base final {
public:
    virtual void show() { std::cout << "Base::show()\n"; } // Virtual function
};

class Derived  : public Base {
public:
    void show() override { std::cout << "Derived::show()\n"; } // Overriding function
};
