#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    std::string _employee_name {""};
    int _employee_id {0};
    std::string _joining_date {""};
    std::string _designation;
public:
    Employee() = default;
    Employee(const Employee&) = default;
    Employee(Employee&&) = delete;
    Employee& operator = (const Employee&) = default;
    Employee&& operator = (Employee&&) = delete;

    Employee(std::string employee_name, int employee_id, std::string joining_date, std::string designation);

    std::string employeeName() const { return _employee_name; }

    int employeeId() const { return _employee_id; }

    std::string joiningDate() const { return _joining_date; }

    std::string designation() const { return _designation; }
    void setDesignation(const std::string &designation) { _designation = designation; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
