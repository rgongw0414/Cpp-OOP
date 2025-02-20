    
#include <iostream>
#include <string>

class Person {
public:
    virtual void introduce() {
        std::cout << "I am a person" << std::endl;
    }
    virtual ~Person() {}
    

    virtual void setName(const std::string& name) {
        this->name = name;
    }

    virtual std::string getName() const {
        return name;
    }

protected:
    std::string name;
}; 

class Student : public Person { 
public:
    // override keyword is used to indicate that the function is intended to override a virtual function in the base class.
    /* Simpler Code: Base class pointers can simplify your code by reducing the need for conditional statements to check object types. 
    Virtual functions ensure the correct method is called, and 'override' ensures the interface b/w base/derived function is consistent, 
    reducing the likelihood of errors. */
    void introduce() override {
        std::cout << "I am a student, my name is " << getName() << std::endl;
    }

    // The argument not consistent with the base one (which is empty), and 'override' keyword is used, so it will generate error during compilation.
    /* 
    void introduce(std::string whatever) override {
        ...
    } 
    */

    void setName(const std::string& name) override {
        Person::setName(name);
    }
    
    std::string getName() const override {
        return Person::getName();
    }
};

class Teacher : public Person {
public:
    void introduce() override {
        std::cout << "I am a teacher" << std::endl;
    }

    void setName(const std::string& name) override {
        Person::setName(name);
    }
    
    std::string getName() const override {
        return Person::getName();
    }
};

int main() {
    Person* person = new Person();
    Person* student = new Student();
    Person* teacher = new Teacher();

    person->introduce();
    student->introduce();
    teacher->introduce();

    delete person;
    delete student;
    delete teacher;

    return 0;
}
 
/*
In the code above, we have a  Person  class with a virtual method  introduce()  that prints “I am a person”. We also have a  Student  class and a  Teacher  class that inherit from the  Person  class. Both the  Student  and  Teacher  classes override the  introduce()  method to print “I am a student” and “I am a teacher” respectively. 
In the  main()  function, we create a  Person  object, a  Student  object, and a  Teacher  object. We call the  introduce()  method on each object. Since the  introduce()  method is virtual, the method that is called is determined by the type of the object. 
When we run the program, the output will be: 
I am a person
I am a student
I am a teacher

In this example, we have demonstrated polymorphism using virtual functions. 
Conclusion 
Polymorphism is a powerful feature of object-oriented programming that allows you to write code that is more flexible and easier to maintain. In this tutorial, we discussed the concept of polymorphism and how it can be implemented in C++. We also discussed the different types of polymorphism, including compile-time polymorphism and runtime polymorphism. 
If you have any questions or feedback, feel free to leave a comment. 
About the authors 

  Sajjad Heydari 

Sajjad Heydari is a Full Stack Software Developer with a passion for writing technical content. He focuses on cloud-based solutions, software development, and neural networks. 

  Brian Boucheron 

Brian is a software developer with over 7 years of experience in software development, system administration, and system architecture. He is an AWS Certified Solutions Architect and a Microsoft Certified Azure Solutions Architect.
*/