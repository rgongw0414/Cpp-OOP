#include <iostream>
#include <string>

// When s_str is declared static, including static.cpp will make s_str internal to main.cpp (i.e., the translation unit of main.cpp will have its own s_str, so no linking error will occur)

// #include "static.cpp"  // either declare s_str in main.cpp or include static.cpp
std::string s_str = "s_str in main.cpp"; 

/*
std::string g_str = "g_str in main.cpp"; // duplicated declaration, because g_str is visible to other translation units (.cpp files)

which resulting in multiple definition of g_str:
    $ g++ main.cpp static.cpp global.cpp && ./a.out
        /usr/bin/ld: /tmp/ccnQiFX5.o:(.data+0x4): multiple definition of `g_str'; /tmp/ccXnZGhB.o:(.data+0x4): first defined here
        collect2: error: ld returned 1 exit status
*/
// to use g_str from static.cpp, use extern std::string g_str; to declare it
extern std::string g_str; // declaration ensures no multiple definitions

int main() {
    // g_str = "g_str modified in main()"; // though g_str is declared in global.cpp, it is visible to main.cpp, and can be modified
    // s_str = "s_str modified in main()"; // s_str is declared in static.cpp, and is visible to main.cpp, and can be modified
    std::cout << s_str << std::endl; // output: s_str in static.cpp
    std::cout << g_str << std::endl; // output: g_str in global.cpp
    return 0;
}