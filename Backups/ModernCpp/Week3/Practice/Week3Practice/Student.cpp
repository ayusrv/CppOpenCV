#include "Student.h"
std::ostream &operator<<(std::ostream &os, const Student &rhs)
{
    os << "_name: " << rhs._name
       << " _gender: ";
    if (rhs._gender == Gender::MALE)
    {
        os << "Male ";
    }
    else if (rhs._gender == Gender::FEMALE)
    {
        os << "Female ";
    }
    else
    {
        os << "NO comments ";
    }
    os << " _age: " << rhs._age
       << " _roll_no: " << rhs._roll_no
       << " _class_teacher: " << rhs._class_teacher;
    return os;
}

Student::Student(std::string name, Gender gender, int age, int roll_no, std::string class_tacher)
    : _name{name}, _gender{gender}, _age{age}, _roll_no{roll_no}, _class_teacher{class_tacher} {}