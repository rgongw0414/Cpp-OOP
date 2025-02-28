
### Compiler
* Preprocess (#include, #define, ...)
  * ```#include <...>``` copy and paste the code
  * ```#define A B``` replace A with B
* Compile cpp files into obj files (binary), which might not be executable, and needed to linked with other obj files to build the final executable
  

### Linker
* Translation unit -> translation symbol
  * Translation Unit: 
  
  The basic unit of compilation in C++. It consists of a single source file (.cpp) and all the headers (#include) files that it includes. The compiler processes this as a single entity, generating an object file (.o) for each translation unit.

  * Translation Symbol: 

  An individual name (such as a function or variable) that is used in different translation units. During the linking phase, these symbols are resolved to ensure that all references to functions and variables across translation units are correctly linked.

* Each cpp file is compiled into seperated obj file, and linked into one executable binary file
* Link all obj files together (link the obj files of the functions in seperated cpp files)
  * insert the obj (binary) files into where the functions are called
* Define the entry point of the program

#### Avoid Duplicated Translation Symbols
  * Seperate the declaration & the implementation of functions into different files (.h & .cpp)
  * Such that same functions are not decalred twice, making linking failed (the linker don't know which symbol to link to)
  * For a function, there should be only one translation unit per function declaration & per function implementation
