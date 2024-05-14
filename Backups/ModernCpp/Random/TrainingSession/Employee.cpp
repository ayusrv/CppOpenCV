#include "Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_employee_name: " << rhs._employee_name
       << " _employee_id: " << rhs._employee_id
       << " _joining_date: " << rhs._joining_date
       << " _designation: " << rhs._designation;
    return os;
}

Employee::Employee(std::string employee_name, int employee_id, std::string joining_date, std::string designation)
        :_employee_name(employee_name), _employee_id(employee_id), _joining_date(joining_date), _designation(designation) {}