#include "ClassA.h"
std::ostream &operator<<(std::ostream &os, const ClassA &rhs) {
    os << "age: " << rhs._age
       << " name: " << rhs._name;
    return os;
}

ClassA::ClassA(int age, std::string name) : _age{age}, _name{name} {}