#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Project.h"
#include <iostream>
#include <memory>

class Employee
{
private:
    std::string _employee_id;
    std::string _employee_name;
    float _salary;
    std::shared_ptr<Project> _project;
public:
    Employee() = delete; //Deleting the default constructor
    ~Employee() = default; //Defult of Destructor
    Employee(const Employee&) = delete; //Deleting the Copy COnstructor
    Employee(Employee&&) = delete; //Deleteing the move symantic
    Employee& operator = (Employee&) = delete; //Deleting the = operator
    Employee& operator = (Employee&&) = delete; //Deleting the = operator
    Employee(std::string employee_id, std::string employee_name, float salary, std::shared_ptr<Project> project);

    float TaxExemptionAmount();

    std::string employeeId() const { return _employee_id; }
    void setEmployeeId(const std::string &employee_id) { _employee_id = employee_id; }

    std::string employeeName() const { return _employee_name; }
    void setEmployeeName(const std::string &employee_name) { _employee_name = employee_name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    std::shared_ptr<Project> project() const { return _project; }
    void setProject(const std::shared_ptr<Project> &project) { _project = project; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
