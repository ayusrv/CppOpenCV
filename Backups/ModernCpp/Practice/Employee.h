#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "Gender.h"
#include "EmployeeType.h"

class Employee
{
private:
    std::string _name;
    std::string _address;
    int _age;
    Gender _gender;
    float _salary;
    EmployeeType _emp_type;

public:
    Employee() = default;
    Employee(const Employee&) = default;
    Employee(Employee&&) = default;
    Employee& operator=(const Employee&) = default;
    Employee& operator=(Employee&&) = default;
    Employee(std::string name, std::string address, int age, Gender gender, float salary, EmployeeType emp_type);
    virtual float CalculateTax() = 0;

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    std::string address() const { return _address; }
    void setAddress(const std::string &address) { _address = address; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }

    Gender gender() const { return _gender; }
    void setGender(const Gender &gender) { _gender = gender; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    EmployeeType empType() const { return _emp_type; }
    void setEmpType(const EmployeeType &emp_type) { _emp_type = emp_type; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
