#include <iostream>
using namespace std;

/*
Virtual Base Classes in Multiple Inheritance
Why: In multiple inheritance, using a virtual base class ensures that the base class is shared among the derived classes, preventing multiple copies of the base class subobject.
   A
  / \
 B   C
  \ /
   D
*/
class A {
    // Base class

    public:
        A() { cout << "A constructed" << endl; }
        virtual ~A() { cout << "A destructed" << endl; } // Virtual destructor, ref: binding/v_destructor.cpp
        virtual void v_func() = 0;
        // Pure virtual function
        // A class with a pure virtual function is called an abstract class, and it cannot be instantiated.
        // Derived classes must override the pure virtual function to be instantiated.
};

void A::v_func() {
    cout << "A's implementation of v_func" << endl;
}

class B : virtual public A {
    // Derived class B with virtual inheritance
    
    public:
        B() { cout << "B constructed" << endl; }
        virtual ~B() { cout << "B destructed" << endl; }
        void v_func() override { cout << "B's implementation of v_func" << endl; }
};

class C : virtual public A {
    // Derived class C with virtual inheritance
    public:
        C() { cout << "C constructed" << endl; }
        virtual ~C() { cout << "C destructed" << endl; }
        void v_func() override { cout << "C's implementation of v_func" << endl; }
};

class D : public B, public C {
    // D inherits from B and C, both virtually inheriting from A
    public:
        D() { cout << "D constructed" << endl; }
        virtual ~D() { cout << "D destructed" << endl; }
        void v_func() override { cout << "D's implementation of v_func" << endl; }
        void additionalMethod() { cout << "D's additional method" << endl; }
};

int main() {
    D d;
    d.v_func();
    d.additionalMethod();

    return 0;
}