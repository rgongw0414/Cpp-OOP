## Polymorphism
* If an instance sends a stimulus to another instance, but does not have to be aware of which class the receiving instance belongs to, we say that we have polymorphism.
* Common Implementation
  * Pointer casting:
  ``` c++
  Derived* derived_ptr = new Derived();
  Base* base_ptr = dynamic_cast<Base*>(derived_ptr);  // upcasting
  ```
  * Manage the interface in a top-down (Base-Derived) manner, so that we can modify the code from Base, which enables minimun modification
  * 'override'keyword: check the derived functions are consistent with the interface in Base class, if not, raise error in compile-time
  ``` c++
  class Base {
  public:
      virtual void func1(const string str) { cout << str << endl; }
  }

  class Derived : public Base {
      // Since 'override' is used, this would generate error during compilation, because it is not consistent with Base::func1(const string str)
      // void func1(const char* str) override { cout << "overrided func1 of Derived: " << str << endl; }
      void func1(const string str) override { cout << "overrided func1 of Derived: " << str << endl; }
  }
  ```
