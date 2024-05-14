#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include <memory>
#include <algorithm>
#include <numeric>

using EmployeeContainer = std::vector<Employee>;
using EmployeePointerContainer = std::vector<Employee*>;
using EmpSptr = std::shared_ptr<Employee>;
using EmployeeSmartPointerContainer = std::vector<EmpSptr>;

void CreateEmployees(EmployeeContainer& data)
{
    data.push_back(Employee("Ayush", 20000, "ASE", 1));
    data.push_back(Employee("Aman", 30000, "SDE", 4));
    data.push_back(Employee("Rahul", 25000, "Trainer", 3));
    data.push_back(Employee("Raj", 40000, "SDE", 6));
}
void CreateEmployeesPointer(EmployeePointerContainer& data)
{
    data.push_back(new Employee("Ayush", 20000, "ASE", 1));
    data.push_back(new Employee("Aman", 30000, "SDE", 4));
    data.push_back(new Employee("Rahul", 25000, "Trainer", 3));
    data.push_back(new Employee("Raj", 40000, "SDE", 6));
}
void CreateEmployeesSmartPointer(EmployeeSmartPointerContainer& data)
{
    data.push_back(std::make_shared<Employee>("Ayush", 20000, "ASE", 1));
    data.push_back(std::make_shared<Employee>("Aman", 30000, "SDE", 4));
    data.push_back(std::make_shared<Employee>("Rahul", 25000, "Trainer", 3));
    data.push_back(std::make_shared<Employee>("Raj", 40000, "SDE", 6));
}

bool check(const Employee& e){
    return e.designation()=="SDE";
}

#endif // FUNCTIONALITIES_H
