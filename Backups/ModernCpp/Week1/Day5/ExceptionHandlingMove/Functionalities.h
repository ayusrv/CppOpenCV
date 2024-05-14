#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "ClassB.h"
#include<vector>
using conatiner = std::vector<ClassB*>;

void CreateObject(conatiner &data);
void PrintObject(conatiner &data);
void DeleteObject(conatiner &data);

#endif // FUNCTIONALITIES_H
