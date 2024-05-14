#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <variant>

#include "CorporateEmployee.h"
#include "Government.h"

using EmployeePtr = std::shared_ptr<Employee>;
using EmployeeVector = std::vector<EmployeePtr>;
using Container = std::unordered_map<EmployeePtr, EmployeeVector>;

void CreateData(Container& data);
void DisplayObject(Container& data);
float AverageSalary(Container& data, std::string name);
std::string findManagerId(Container& data, std::variant<std::string, int> ide);
int countEmployee(Container& data, std::string name);
EmployeePtr ManagerDetails(Container& data, std::string name);
float getTax(Container& data, std::string name);


#endif // FUNCTIONALITIES_H