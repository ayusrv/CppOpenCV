#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Project.h"
#include <vector>

void CreateObjects(Employee** employees, Project** project);
void CreateObjects(std::vector<Employee*>& employees,std::vector<Project*>& project);


#endif // FUNCTIONALITIES_H
