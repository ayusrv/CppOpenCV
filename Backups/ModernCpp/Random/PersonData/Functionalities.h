#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include "Person.h"

using Container = std::vector<Person*>;

void CreateObject(Container &data);

void printData(Container &data);

void DeleteObject(Container &data);

#endif // FUNCTIONALITIES_H
