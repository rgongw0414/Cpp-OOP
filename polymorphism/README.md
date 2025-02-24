## Polymorphism
* If an instance sends a stimulus to another instance, but does not have to be aware of which class the receiving instance belongs to, we say that we have polymorphism.
* Common Implementation
  * Pointer casting:
  ``` c++
  Derived* derived_ptr = new Derived();
  Base* base_ptr = dynamic_cast<Base*>(derived_ptr);  // upcasting
  ```
  * Manage the interface in a top-down (Base-Derived) manner, so that we can modify the code from Base, which enables minimun modification
  * 'override' keyword: check the derived functions are consistent with the interface in Base class, if not, raise error in compile-time
  ``` c++
  class Base {
  public:
      virtual void func1(const string str) { cout << str << endl; }
      // ...
  };

  class Derived : public Base {
      // Since 'override' is used, this would generate error during compilation, because it is not consistent with Base::func1(const string str)
      // void func1(const char* str) override { cout << "overrided func1 of Derived: " << str << endl; }
      void func1(const string str) override { cout << "overrided func1 of Derived: " << str << endl; }
      // ...
  };
  ```
### Virtual Functions
* Abstract Class
  * At least one pure virtual function delared in class
* Pure Virtual Function
  * Force the derived classes to override the implementation of the pure virtual functions
  * Message: For this function, only the interface is inherited. The implementation is left to be overriden in derived classes.
* (Simple/Normal) Virtual Function
  * Message: For this function, both the interface and the implementation are inherited, the derived classes can choose to either override it, or not to.
  * If not overriden, the function inherited from Base will be called.
* Non-virtual Function
  * Message: Inherit the interface, and keep the implementation untouched (no overriding)
  * Resolved in compile-time (static binding)
  * Overriding them in the derived class does not achieve polymorphic behavior
    * Upon calling the same function with a Derived object and a Base object, the output is the same, i.e., this is not polymorphic behavior.
    * binding/non_v_func.cpp
* Virtual Destructor
  * Non-virtual destructor makes the destructor of the derived class not called, resulting in incomplete destruction.
* Overriding Virtual Functions
  * Given an abstract class: Base, if the pure virtual function is not overriden in derived classes, the derived classes would become abstract, making it cannot be used to instantiate objects (except for virtual destructor, because the compiler generates a default destructor).
  * binding/v_desturctor.cpp
  * binding/not_overriding_vFunc.cpp
