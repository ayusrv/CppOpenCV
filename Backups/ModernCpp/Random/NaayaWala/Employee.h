#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include <functional>
#include <ostream>
#include "Project.h"

class Employee
{
private:
    int _id;
    std::reference_wrapper<Project> _projects;

public:
    Employee()=default;
    Employee(const Employee &)=delete;
    Employee(Employee && )=delete;
    Employee & operator=(const Employee & )=delete;
    Employee &operator=(Employee &&)=delete;
    ~Employee()=default;
    Employee(int id, std::reference_wrapper<Project> projects);

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
