#include <iostream> 
#include <string>

class Shape {
    static int nextID;
    int id;
public:
    virtual void draw() const = 0; // pure virtual function
    virtual void error(const std::string& msg) {
        // (simple) virtual function: can be overridden in derived classes, if it's not overridden in derived classes, the base class function will be called, i.e., the interface is inherited, but the implementation is not.
        // however, if this function is overridden in the derived class, the base class function will not be called, i.e. both interface and implementation are inherited.
        std::cerr << "Shape Error: " << msg << std::endl;
    } 
    Shape() : id(nextID++) {}
    virtual ~Shape() {}
    int getObjectID() const { return id; } // non-virtual function: had better not overridden in derived classes, i.e., inherit both the interface and implementation, and *do not* modify the inherited implementation.
}; // since there're pure virtual functions, this class is abstract and cannot be instantiated, but can be used as a base class for derived.

int Shape::nextID = 1;

class Rectangle: public Shape {
    void draw() const override {
        std::cout << "Drawing Rectangle" << std::endl;
    }

    void error(const std::string& msg) override {
        std::cerr << "Rectangle Error: " << msg << std::endl;
    }
};

class Ellipse: public Shape {
    void draw() const override {
        std::cout << "Drawing Ellipse" << std::endl;
    }

    // not overriding the error function, so the base class function will be called.
    // void error(const std::string& msg) override {
    //     std::cerr << "Ellipse Error: " << msg << std::endl;
    // }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Rectangle();
    shapes[1] = new Ellipse();

    for (int i = 0; i < 2; i++) {
        std::cout << "Object ID: " << shapes[i]->getObjectID() << std::endl;
        shapes[i]->draw();
        shapes[i]->error("My Error");
    }

    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}