#include <iostream>

class Entity {
public:
    static int s_x, s_y; // The scope of static variable is the class, not the object
    int ns_x, ns_y;
    static void Print() { // static member function cannot access non-static member variable
        std::cout << s_x << ", " << s_y << std::endl;

        // Error: A nonstatic member reference must be relative to a specific object
        // std::cout << n_x << ", " << n_y << std::endl; // Error: static member function cannot access non-static member variable
    }
};

/*
if Print is non-static function, then it can access non-static member variable
Actually, non-static functions are taking an implicit parameter (this), which is the object itself:
void Entity::Print(Entity& e) {
    std::cout << e.n_x << ", " << e.n_y << std::endl;
}
*/

int Entity::s_x; // static variable must be defined outside the class
int Entity::s_y;

int main() {
    Entity::s_x = 10;
    Entity::s_y = 20;
    Entity::Print();
    return 0;
}