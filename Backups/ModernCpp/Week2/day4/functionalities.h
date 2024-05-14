#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <vector>
#include <functional>

using Container = std::vector<int>;
using FType = std::function<void(Container&)>;

void Adaptor(FType fn, Container& data);

extern FType lfn1;
extern FType lfn2;
extern FType lfn3;

#endif // FUNCTIONALITIES_H
