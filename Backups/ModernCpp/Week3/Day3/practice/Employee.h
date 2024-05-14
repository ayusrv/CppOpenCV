#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "EmployeeType.h"

class Employee
{
private:
    std::string _name;
    float _salary;
    EmployeeType _employee_type; 
    
public:
    Employee()=default;
    Employee(const Employee &)=delete;
    Employee(Employee && )=delete;
    Employee & operator=(const Employee & )=delete;
    Employee &operator=(Employee &&)=delete;
    ~Employee()=default;
    Employee(std::string name, float salary, EmployeeType employee_type);
    
    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    EmployeeType employeeType() const { return _employee_type; }
    void setEmployeeType(const EmployeeType &employee_type) { _employee_type = employee_type; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
