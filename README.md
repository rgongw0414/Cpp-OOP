# Polymorphism
* If an instance sends a stimulus to another instance, but does not have to be aware of which class the receiving instance belongs to, we say that we have polymorphism.
* Polymorphism is saying that the behavior of an object in response to an event (function call) is determined by the object itself
* To achieve Polymorphism in C++, one can coordinate virtual functions, and class inheritance, etc.
  * [polymorphism/person.cpp](polymorphism/person.cpp)
  ``` c++
  class Person {
  public:
      // ...
      virtual ~Person() {} // ensure the derived class destructors are called properly.
      // Pure virtual function: Indicates that the derived classes must override this function, otherwise they cannot initiate objects.
      virtual void greeting() = 0; // makes the class abstract and cannot be instantiated.
      // ...
  }; 

  class American : public Person {
  public:
      // ...
      void greeting() override {
          cout << "Nice to meet you! I am " << this->getName() << ". How's going?" << endl;
      }
  };

  class Japanese : public Person {
  public:
      // ...
      void greeting() override {
          cout << "こんにちは" << endl; 
      }
  };

  class Taiwanese : public Person {
  public:
      // ...
      void greeting() override {
          cout << "你好" << endl; 
      }
  };

  int main() {
    Person* american = dynamic_cast<Person*>(new American("John Doe"));
    Person* japanese = dynamic_cast<Person*>(new Japanese("鈴木太郎"));
    Person* taiwanese = dynamic_cast<Person*>(new Taiwanese("陳太明"));
    // For each class, the function print different messages
    american->greeting();  // Output: Nice to meet you! I am John Doe. How's going?
    japanese->greeting();  // Output: こんにちは
    taiwanese->greeting(); // Output: 你好
    // ...
  }
  ```
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
## Virtual Functions
#### Abstract Class
* At least one pure virtual function delared in class
* Can't be used to initiate objects, can only be the ***interface*** to the derived classes
#### Pure Virtual Function
* Force the derived classes to override the implementation of the pure virtual functions
* Message: For this function, only the interface is inherited. The implementation is left to be overriden in derived classes.
#### (Simple/Normal) Virtual Function
* Message: For this function, both the interface and the implementation are inherited, the derived classes can choose to either override it, or not to.
* If not overriden, the function inherited from Base will be called.
#### Non-virtual Function
* Message: Inherit the interface, and keep the implementation untouched (no overriding)
* Resolved in compile-time (static binding)
* Overriding them in the derived class does not achieve polymorphic behavior
  * Upon calling the same function with a Derived object and a Base object, the output is the same, i.e., this is not polymorphic behavior.
  * [binding/non_v_func.cpp](binding/non_v_func.cpp)
#### Virtual Destructor
* Non-virtual destructor makes the destructor of the derived class not called, resulting in incomplete destruction.
#### Overriding Virtual Functions
* Given an abstract class: Base, if the pure virtual function is not overriden in derived classes, the derived classes would become abstract, making it cannot be used to instantiate objects (except for virtual destructor, because the compiler generates a default destructor).
* [binding/v_desturctor.cpp](binding/v_desturctor.cpp)
* [binding/not_overriding_vFunc.cpp](binding/not_overriding_vFunc.cpp)
#### Refs:
* [C++中關於 virtual 的兩三事](https://medium.com/theskyisblue/c-中關於-virtual-的兩三事-1b4e2a2dc373)
* [Why a pure virtual destructor needs an implementation](https://stackoverflow.com/questions/21109417/why-a-pure-virtual-destructor-needs-an-implementation)

## Virtual Table (vtable)
* One of the most common methods to achieve polymorphism
* In many C++ implementations, the virtual table pointer is the first sizeof(void (**)()) bytes (4 or 8) of the object
* When dereferencing the vtable pointer, you get the starting address of the virtual table: __vptr
  * *vtable_ptr -> __vptr
* __vptr is a hidden member
  *  An pointer pointing to function pointers (virtual functions)
  *  vtable __vptr is an array of function pointers, which is of type `void (*[])()`
     *  Each entry is of type `void (*)()` (function pointer)
     *  So we can do a little trick to access __vptr, which is by explicitly convert the obj address to `void (***)()` (a ptr to ptr to function ptrs) manually, then dereference it to get the ptr to function ptrs (array of ptrs).
     ``` cpp
     Derived derivedObj;
     Base* base_ptr = &derivedObj;
     void (**vtable)() = *reinterpret_cast<void (***)()> (&derivedObj);
     vtable[0](); // access the first virtual function
     ```
* Ecah objects has their own vtables, if there is at least one virtual function in the class
  * [binding/v_table.cpp](binding/v_table.cpp)
* Given class Base and Derived:
``` cpp
class Base
{
public:
    virtual void function1() {}
    virtual void function2() {}
    void function3() {}
};
 
class Derived: public Base
{
public:
    virtual void function1() {}
};

int main()
{
    Derived d1;
    Base *d1_basePtr = &d1; // view d1 as Base
}
```
* For Base, the __vptr looks like:
``` cpp
struct __vptr {
	void (*function1)();
	void (*function2)();
}
```
* As for Derived:
  * For each entry, it will be the "most-derived" version of function
``` cpp
struct D1_vptr {
	function1 = Derived_function1;
	function2 = Base_function2;
}
```
* For d1_basePtr, it is a Derived obj being viewed as Base
* Derived is derived from Base, so __vptr can still access the right functions
* Refs:
  * [C++ 內部如何實現多型](https://npes87184.github.io/2019-06-08-how-c++-achieve-polymorphism-internally/)
  * [stack overflow: A helper variable for virtual table in c++](https://stackoverflow.com/questions/18246016/void-vt-void-ptr-a-helper-variable-for-virtual-table-in-c)
  * [Code Project: Displaying vtable when debugging](https://www.codeproject.com/Tips/90875/Displaying-vtable-when-debugging)
  * [Learn C++: 25.6 — The virtual table](https://www.learncpp.com/cpp-tutorial/the-virtual-table/)