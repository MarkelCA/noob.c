#include <iostream>
#include <utility>
#include "ExplicitConstructors/Printer.h"
#include "InterfaceInheritance/Person.h"
#include "InterfaceInheritance/Student.h"

class Entity{
    std::string name;
    int age;
public:
    Entity(std::string  name) :
            name(std::move(name)), age(-1){}
    Entity(int age)
            :name("Unknown"), age(age){}

        void sayHi() {
            std::cout << "Hi";
        }
};

int main() {
    Entity markel("markel");
    Entity juan = 4 ;
    juan.sayHi();

    Entity sett = 3;
    std::string aoeu = "aoe";
    Entity test = aoeu;

    std::cout << "Hello, World!" << std::endl;
    Printer myprinter("aoeu");
    std::cout << myprinter.message;

    Person noe;
    noe.sayHi();

    Student jomario;
    jomario.sayHi();

    return 0;
}
