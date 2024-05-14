#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <vector>
#include "BankDetails.h"

using Container = std::vector<BankDetails*>;
void CreateObject(Container &data);
void PrintObject(Container &data);
void DeleteObject(Container &data);
int MinimumBalance(Container &data);

#endif // FUNCTIONALITIES_H
