#include "CorporateEmployee.h"
std::ostream &operator<<(std::ostream &os, const CorporateEmployee &rhs) {
    os << static_cast<const Employee &>(rhs)
       << " _id: " << rhs._id;
    return os;
}

CorporateEmployee::CorporateEmployee(std::string name, std::string address, int age, Gender gender, float salary, EmployeeType emp_type, std::string id)
                : Employee(name, address, age, gender, salary, emp_type), _id{id} {}

float CorporateEmployee::CalculateTax()
{
    return 0.15*this->salary();
}