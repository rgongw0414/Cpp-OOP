    
#include <iostream>
#include <string>
using namespace std;

// To demonstrate polymorphism, we will create a base class called Person.
// This class will have a virtual function called introduce() that will be overridden by the derived classes.
// The introduce() function will print a message that identifies the object as a person, student, or teacher.
// The Person class will also have a virtual destructor to ensure that the derived classes' destructors are called properly.
// The Person class will have two virtual functions called setName() and getName() to set and get the name of the person.
// The derived classes (Student and Teacher) will override these functions to provide their own implementations.

class Person {
public:
    // virtual Person(const string name) : name(name) {} // Constructors cannot be virtual, whether Base or Derived or not, they all need a constructor to create an object.
    Person(const string name) : name(name) {}
    Person() : name("") {}
    virtual ~Person() {} // virtual destructor is used to ensure that the derived class destructors are called properly.

    // Pure function: Indicates that the derived classes must override this function, otherwise they cannot initiate objects.
    virtual void greeting() = 0; // pure virtual function, which makes the class abstract and cannot be instantiated.

    //  set/getName() are not virtual, because they are not intended to be overridden by the derived classes.
    void setName(const string& name) {
        this->name = name;
    }

    string getName() const {
        return name;
    }

protected:
    string name;
}; 

// The Student class is derived from the Person class and overrides the introduce() function to print a message identifying the object as a student.
// The setName() and getName() functions are also overridden to call the base class implementations.
class American : public Person {
public:
    American(const string name) : Person(name) {}
    ~American() {}
    void greeting() override {
        // override is to ensure that the function is intended to override a virtual function in the base class.
        // Also, if the interface of the base class' functions is not consistent with the derived class, the compiler will generate an error.
        // This helps to catch errors at compile time rather than runtime.
        // For further information, refer to the override.cpp file.
        cout << "Nice to meet you! I am " << this->getName() << ". How's going?" << endl;
    }
};

class Japanese : public Person {
public:
    Japanese(const string name) : Person(name) {} 
    ~Japanese() {}
    void greeting() override {
        cout << "こんにちは" << endl; 
    }
};

class Taiwanese : public Person {
public:
    Taiwanese(const string name) : Person(name) {} 
    ~Taiwanese() {}
    void greeting() override {
        cout << "你好" << endl; 
    }
};

int main() {
    // By using the base class pointer as a interface b/w derived classes, we store derived class objects in the same container, which incorporates virtual functions to call the correct function at runtime.
    // This is called polymorphism.
    /* Casting derived ptrs to base ptrs and use virtual functions, why is this a good style?
    1. It provides a clear separation between the interface and implementation. 
    You can define a common interface in the base class and have different implementations in derived classes.  
    2. You can write code that works with base class pointers, and it will automatically handle any derived class object, making your code more flexible and extensible. */
    Person* american = dynamic_cast<Person*>(new American("John Doe"));
    if (american == nullptr) { 
        // dynamic_cast is used to cast a pointer or reference to a derived class to a pointer or reference to a base class.
        // If the cast is successful, the dynamic_cast will return a pointer or reference to the base class.
        // If the cast fails, the dynamic_cast will return a nullptr.
        // dynamic_cast is also used for downcasting (casting from a base class to a derived class) and is safer than static_cast because it performs a runtime check to ensure that the cast is valid.
        cout << "Failed to cast American to Person" << endl;
        throw std::runtime_error("Failed to cast American to Person");
    }
    Person* japanese = dynamic_cast<Person*>(new Japanese("鈴木太郎"));
    if (japanese == nullptr) { 
        // dynamic_cast is used to cast a pointer or reference to a derived class to a pointer or reference to a base class.
        // If the cast is successful, the dynamic_cast will return a pointer or reference to the base class.
        // If the cast fails, the dynamic_cast will return a nullptr.
        // dynamic_cast is also used for downcasting (casting from a base class to a derived class) and is safer than static_cast because it performs a runtime check to ensure that the cast is valid.
        cout << "Failed to cast Japanese to Person" << endl;
        throw std::runtime_error("Failed to cast Japanese to Person");
    }
    Person* taiwanese = dynamic_cast<Person*>(new Taiwanese("陳太明"));
    if (taiwanese == nullptr) {
        cout << "Failed to cast Taiwanese to Person" << endl;
        throw std::runtime_error("Failed to cast Taiwanese to Person");
    }

    // Call the greeting() function on each object to demonstrate polymorphism.
    // For different objects, the greeting() function will print different messages based on the type of the object, which is determined at runtime.
    american->greeting();  // Output: Nice to meet you! I am John Doe. How's going?
    japanese->greeting();  // Output: こんにちは
    taiwanese->greeting(); // Output: 你好


    // Clean up memory by deleting the objects.
    delete american;
    delete japanese;
    delete taiwanese;
    
    return 0;
}