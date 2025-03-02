#include <iostream>
#include <string>

// const qualifier can be used with member functions to specify that the function does not modify the object
//-Example_1----------------------------------------------------------------------------------------------
class Base {
public:
    virtual void setName (const std::string& name) { this->name = name; }
    virtual std::string getName() const { 
        // this->name = "Base"; // Error: assignment of member ‘Base::name’ in read-only object
        return name; 
    } // const member function can't modify the object content
    virtual ~Base() {}

private:
    std::string name;
};

void PrintBase(const Base* b) {
    b = new Base(); // no error
    b->setName("Base"); // Error: object type is: const Base, the object has type qualifiers that are not compatible with the member function "Base::setName"
    std::cout << b->getName() << std::endl;
}

void PrintBase2(Base* const b) {
    b = new Base(); // Error: expression must be a modifiable lvalue
    b->setName("Base"); // no error
    std::cout << b->getName() << std::endl;
}

//-Example_2----------------------------------------------------------------------------------------------

class Entity {
public:
    virtual void setName (const std::string& name) { this->name = name; }
    virtual std::string getName() { 
        // this->name = "Entity"; // No error: non-const member function can modify the object content
        return name; 
    } // const member function can't modify the object content
    virtual ~Entity() {}

private:
    std::string name;
};

void PrintEntity(const Entity* e) {
    // e is const* so we can't modify the object content
    // Entity::getName() is not a const function so we can't call it
    std::cout << e->getName() << std::endl; // Error: the object has type qualifiers that are not compatible with the member function "Entity::getName"

    // Only const member functions can be called on a const object!!!
}


//-Example_3----------------------------------------------------------------------------------------------
// Overloading const and non-const member functions
// If a member function does not modify the object, it should be declared as const
// If a member function modifies the object, it should not be declared as const
class Example {
public:
    void display() const { // const version
        std::cout << "Const display\n";
    }

    void display() { // non-const version
        std::cout << "Non-const display\n";
    }
};

int main() {
    const Example constObj;
    Example nonConstObj;

    constObj.display();   // Calls the const version
    nonConstObj.display(); // Calls the non-const version

    return 0;
}
    
