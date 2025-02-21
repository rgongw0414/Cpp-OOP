## Avoiding Virtual with Inline Functions
* Why: Declaring a function as both virtual and inline can be problematic because inline suggests that the function should be expanded inline, while virtual indicates that it should be called through the virtual table, which cannot be resolved at compile time.

* What should we do: Avoid using inline with virtual functions, as it can lead to undefined behavior and unpredictable performance.