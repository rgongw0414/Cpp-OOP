#include <string>

std::string g_str = "g_str in global.cpp"; // example of global variable declaration, visible to other .cpp files
// if declaring g_str in another .cpp file, use extern std::string g_str; to declare it, otherwise linker error will occur because of multiple definitions