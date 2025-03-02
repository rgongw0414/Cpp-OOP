// auto generated default functions:
class Empty {
public:
    Empty();  // Default constructor
    ~Empty(); // Default destructor

    Empty(const Empty&); // Copy constructor
    Empty& operator=(const Empty&); // Copy assignment operator

    Empty* operator&(); // Address-of operator
    const Empty* operator&()const; // const Address-of operator
    
    Empty(Empty&&); // Move constructor
    Empty& operator=(Empty&&); // Move assignment operator
};