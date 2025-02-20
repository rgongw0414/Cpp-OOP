## Polymorphism
* If an instance sends a stimulus to another instance, but does not have to be aware of which class the receiving instance belongs to, we say that we have polymorphism.
* Common Implementation
  * Pointer casting (dynamic_cast<Base*>(derived_ptr);)
  * Manage the interface in a top-down (Base-Derived) manner, so that we can modify the code from Base, which enables minimun modification
  * 'override'keyword: check the derived functions are consistent with the interface in Base class, if not, raise error in compile-time
