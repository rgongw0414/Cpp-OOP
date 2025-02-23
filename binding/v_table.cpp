#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    virtual void func1() {
        cout << "Base class func1" << endl;
    }
    virtual void func2() {
        cout << "Base class func2" << endl;
    }
    virtual void func3() {
        cout << "Base class func3" << endl;
    }
};

class Derived : public Base {
public:
    void func1() override {
        cout << "Derived class func1" << endl;
    }
    void func2() override {
        cout << "Derived class func2" << endl;
    }
    void func3() override {
        cout << "Derived class func3" << endl;
    }
};

//     r_type f_name args
typedef void(*FuncPtr)();  // function pointer type

int main() {
    Derived derivedObj;
    Base* baseObj = &derivedObj;
    void** v_table_ptr = *reinterpret_cast<void***>(baseObj);  // baseObj is a ptr to the v_table, where v_table is a array of v_function pointers, so we have to dereference it to get the begining of the v_table.
    cout << "v_table_ptr : " << v_table_ptr << endl;
    int i = 0;
    while (v_table_ptr[i] && i < 3) {
        FuncPtr func = reinterpret_cast<FuncPtr>(v_table_ptr[i]);
        // func: The virtual function pointer in the v_table.
        // v_table_ptr + i: The memory address of each pointer of the virtual function in the v_table.
        // v_table_ptr[i]: The memory address of the virtual function implementation, which is pointed by v_table_ptr + i (aka func).
        cout << "Pointer of Virtual function " << i << " : " << v_table_ptr + i << endl;
        cout << "The address of the virtual function implementation: " << v_table_ptr[i] << endl << "\n";
        func();
        i++;
    }
    return 0;
}