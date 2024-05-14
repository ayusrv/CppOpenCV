#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Major.h"
#include "classA.h"
#include <vector>
#include <memory>

using classAContainer = std::shared_ptr<classA>;
using Pointer = std::shared_ptr<Major>;
using Container = std::vector<Pointer>;

void CreateObject(Container &data1, classAContainer &data);
void getVal(Container &data1);
void operations(std::function<void(int, int)> fn, int n1, int n2);


#endif // FUNCTIONALITIES_H
