#include <string>
// declare static variable outside of a class/struct
// s_str will be visible only in this file, i.e., at linking stage, it will not be visible to other .cpp files (translation units)
static std::string s_str = "s_str in static.cpp"; // example of static variable declaration
// std::string s_str = "s_str in static.cpp"; // resulting of multiple definition of s_str, because it is also declared in main.cpp