// =delete;
// Prevents the generation/use of a function.
// This is useful for preventing the use of a function that should not be used.

class A {
public:
    A() = default;
    A(const A&) = delete; // Prevents generation/use of copy constructor
    A& operator=(const A&) = delete; // Prevents generation/use of copy assignment operator
    ~A() = default;

// in C++98/03, you can do the same by declaring them private and not defining it
// private:
//     A(const A&);
//     A& operator=(const A&);
};

// The auto generated functions, if not explicitly declared, are:
class Empty {
public:
    // Empty();  // Default constructor
    // ~Empty(); // Default destructor

    // Empty(const Empty&); // Copy constructor
    // Empty& operator=(const Empty&); // Copy assignment operator

    // Empty* operator&(); // Address-of operator
    // const Empty* operator&()const; // const Address-of operator
    
    // Empty(Empty&&); // Move constructor
    // Empty& operator=(Empty&&); // Move assignment operator
};

int main() {
    A a1;
    // A a2(a1); // Error: calling the copy constructor that is deleted
    // A a3 = a1; // Error: calling deleted constructor of 'A'
    // a1 = a1; // Error: calling deleted operator '='
    return 0;
}