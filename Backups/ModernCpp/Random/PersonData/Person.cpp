#include "Person.h"
#include<iostream>

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "_name: " << rhs._name
       << " _age: " << rhs._age
       << " _gender: " << rhs._gender
       << " _aadhar: " << rhs._aadhar;
    return os;
}

Person::Person(std::string name, int age, char gender, long aadhar)
        : _name(name), _age(age), _gender(gender), _aadhar(aadhar){}

Person::~Person()
{
}
