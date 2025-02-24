#include <iostream>

class Base {
public:
    void nonVirtualFunction() const {
        std::cout << "Base class non-virtual function" << std::endl;
    }
};

class Derived : public Base {
public:
    void nonVirtualFunction() const {
        std::cout << "Derived class non-virtual function" << std::endl;
    }
};

void callFunction(const Base* obj) {
    obj->nonVirtualFunction();  // Calls Base::non-virtual function
}
    
/* Function Call in callFunction: The function callFunction takes a const Base* parameter. 
When nonVirtualFunction is called on this pointer, the compiler resolves this call based on the static type of the pointer, which is Base.
Therefore, the nonVirtualFunction of the Base class is called, even if the object is of type Derived.
Upon calling the same function with a Derived object and Base, the output is the same, i.e., this is not polymorphic behavior.
*/
int main() {
    Base base;
    Derived derived;

    callFunction(&base);     // Outputs: Base class non-virtual function
    callFunction(&derived);  // Outputs: Base class non-virtual function

    return 0;
}
