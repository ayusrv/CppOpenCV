#include "Functionalities.h"

void CreateObjects(Employee **employees, Project **project)
{
    project[0] = new Project("Pii12", 5000.66f, 11);
    employees[0] = new Employee("emp01", "Harshit", 5600.9f, *project[0]);
}

void CreateObjects(std::vector<Employee*> &employees, std::vector<Project*> &project)
{
    project.push_back(new Project("Pii12", 5000.66f, 11));
    employees.push_back(new Employee("emp01", "Harshit", 5600.9f, *project[0]));
}