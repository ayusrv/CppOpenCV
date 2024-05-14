#include "Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _employee_type: ";
       if(rhs._employee_type == EmployeeType::OVERSEAS) os<<"OVERSEAS";
       else os<<"REGULAR";
    return os;
}

Employee::Employee(std::string name, float salary, EmployeeType employee_type)
        : _name{name}, _salary{salary}, _employee_type{employee_type} {}