    
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
    Person(const string name) : name(name) {}
    Person() : name("") {}

    virtual void introduce() {
        cout << "I am a person" << endl;
    }
    virtual ~Person() {}
    

    virtual void setName(const string& name) {
        this->name = name;
    }

    virtual string getName() const {
        return name;
    }

protected:
    string name;
}; 

// The Student class is derived from the Person class and overrides the introduce() function to print a message identifying the object as a student.
// The setName() and getName() functions are also overridden to call the base class implementations.
class Student : public Person {
public:
    Student(const string name) : Person(name) {}
    Student() : Person() {}
    void introduce() override {
        // override is to ensure that the function is intended to override a virtual function in the base class.
        // Also, if the interface of the base class' functions is not consistent with the derived class, the compiler will generate an error.
        // This helps to catch errors at compile time rather than runtime.
        // For further information, refer to the override/override.cpp file.
        cout << "I am a student, my name is " << this->getName() << endl;
    }

    void setName(const string& name) override {
        Person::setName(name);
    }
    
    string getName() const override {
        return Person::getName();
    }

    ~Student() {}
};

// The Teacher class is derived from the Person class and overrides the introduce() function to print a message identifying the object as a teacher.
// The setName() and getName() functions are also overridden to call the base class implementations.
class Teacher : public Person {
public:
    Teacher(const string name) : Person(name) {}
    Teacher() : Person() {}
    void introduce() override {
        cout << "I am a teacher, my name is " << this->getName() << endl;
    }

    void setName(const string& name) override {
        Person::setName(name);
    }
    
    string getName() const override {
        return Person::getName();
    }

    ~Teacher() {}
};

int main() {
    // Create instances of the Person, Student, and Teacher classes.
    Person* person = new Person();
    
    // By using the base class pointer as a interface b/w derived classes, we store derived class objects in the same container, which incorporates virtual functions to call the correct function at runtime.
    // This is called polymorphism.
    /* Casting derived ptrs to base ptrs and use virtual functions, why is this a good style?
    1. It provides a clear separation between the interface and implementation. 
    You can define a common interface in the base class and have different implementations in derived classes.  
    2. You can write code that works with base class pointers, and it will automatically handle any derived class object, making your code more flexible and extensible. */
    Person* student = dynamic_cast<Person*>(new Student());
    if (student == nullptr) { 
        // dynamic_cast is used to cast a pointer or reference to a derived class to a pointer or reference to a base class.
        // If the cast is successful, the dynamic_cast will return a pointer or reference to the base class.
        // If the cast fails, the dynamic_cast will return a nullptr.
        // dynamic_cast is also used for downcasting (casting from a base class to a derived class) and is safer than static_cast because it performs a runtime check to ensure that the cast is valid.
        cout << "Failed to cast Student to Person" << endl;
        throw std::runtime_error("Failed to cast Student to Person");
    }
    Person* teacher = dynamic_cast<Person*>(new Teacher());
    if (teacher == nullptr) {
        cout << "Failed to cast Teacher to Person" << endl;
        throw std::runtime_error("Failed to cast Teacher to Person");
    }

    person->setName("Person");
    student->setName("Student");
    teacher->setName("Teacher");
    // Call the introduce() function on each object to demonstrate polymorphism.
    // For different objects, the introduce() function will print different messages based on the type of the object, which is determined at runtime.
    person->introduce();
    student->introduce();
    teacher->introduce();


    cout << person->getName() << endl;
    cout << student->getName() << endl;
    cout << teacher->getName() << endl;

    // Clean up memory by deleting the objects.
    delete person;
    delete student;
    delete teacher;
    
    Student* student1 = new Student("Eric");
    student1->introduce();
    delete student1;

    return 0;
}