#include "Teacher.h"
std::ostream &operator<<(std::ostream &os, const Teacher &rhs)
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
       << " _emp_id: " << rhs._emp_id
       << " _salary: " << rhs._salary;
    return os;
}

Teacher::Teacher(std::string name, Gender gender, int age, int emp_id, float salary)
    : _name{name}, _gender{gender}, _age{age}, _emp_id{emp_id}, _salary{salary} {}