#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double area() const = 0;              // Pure virtual function to calculate area
    virtual double perimeter() const = 0;         // Pure virtual function to calculate perimeter
    virtual void draw() const = 0;                // Pure virtual function to draw the shape
    virtual ~Shape() {}
};

// Note: If the implementation of the pure virtual function is not given in derived_obj, the Base pure virtual function would be inherited, making the derived class a *ABSTRACT CLASS*.
// Whether the implementation of Shape::draw() is given or not, when the derived class does not override the function, 
// the base pure virtual function will be inherited, making the derived class a *ABSTRACT CLASS*.
// void Shape::draw() const {
//     std::cout << "Drawing a Shape" << std::endl;
// }

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void draw() const override {
        std::cout << "Drawing a Circle with radius " << radius << std::endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    // void draw() const override {
    //     std::cout << "Drawing a Rectangle with width " << width << " and height " << height << std::endl;
    // }
};

int main() {
    Shape* shapes[] = {
        new Circle(5.0),
        new Rectangle(4.0, 6.0) // error1: invalid new-expression of abstract class type ‘Rectangle’
                                // error2: object of abstract class type "Rectangle" is not allowed: -- pure virtual function "Shape::draw" has no overrider
    };

    for (Shape* shape : shapes) {
        shape->draw();
        std::cout << "Area: " << shape->area() << std::endl;
        std::cout << "Perimeter: " << shape->perimeter() << std::endl;
    }

    // Clean up
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
