#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <vector>
#include "EmptyContainerException.h"
#include "Employee.h"

using Pointer = std::shared_ptr<Employee>;
using Conatiner = std::vector<Pointer>;

void CreateObject(Conatiner &data);
void DisplayObject(Conatiner &data);
int countInstances(Conatiner &data);
bool EmployeesSalary(Conatiner &data);
float AverageTaxExcemption(Conatiner &data);
void NInstances(Conatiner &data, int n);


#endif // FUNCTIONALITIES_H
