#include "Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_name: " << rhs._name
       << " _address: " << rhs._address
       << " _age: " << rhs._age
       << " _gender: ";
    if(rhs._gender == Gender::FEMALE) os<<" Female ";
    else if(rhs._gender==Gender::MALE) os<<" Male ";
    else os<<" Other ";
    os << " _salary: " << rhs._salary
       << " _emp_type: ";
    if(rhs._emp_type == EmployeeType::EMPLOYEE) os<<" Employee ";
    else if(rhs._emp_type==EmployeeType::HR) os<<" HR ";
    else os<<" Manager "; 
    return os;
}

Employee::Employee(std::string name, std::string address, int age, Gender gender, float salary, EmployeeType emp_type)
        : _name{name}, _address{address}, _age{age}, _gender{gender}, _salary{salary}, _emp_type{emp_type} {}