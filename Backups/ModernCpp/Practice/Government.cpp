#include "Government.h"
std::ostream &operator<<(std::ostream &os, const Government &rhs) {
    os << static_cast<const Employee &>(rhs)
       << " _id: " << rhs._id;
    return os;
}

Government::Government(std::string name, std::string address, int age, Gender gender, float salary, EmployeeType emp_type, int id)
            : Employee(name, address, age, gender, salary, emp_type), _id{id} {}
            
float Government::CalculateTax()
{
    return 0.05*this->salary();
}
