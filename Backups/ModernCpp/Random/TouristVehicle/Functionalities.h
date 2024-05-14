#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include "TouristVehicle.h"
#include "EmptyContainerException.h"
#include "SizeNotMatched.h"
#include "NullPointerException.h"
#include "WrongEnumException.h"
#include <functional>

using PermitContainer = std::vector<std::shared_ptr<Permit>>;
using Pointer = std::shared_ptr<TouristVehicle>;
using Container = std::vector<Pointer>;

void CreateObject(Container &data, PermitContainer &data2);
Container NInstances(Container &data, PermitContainer &data2, int n);
float AverageCharge(Container &data, PermitContainer &data2, std::string type);
std::string MaximumCharge(Container &data, PermitContainer &data2);
Container FirstNInstances(Container &data, PermitContainer &data2, int n);
void Adapter(std::function<Container(Container &data, PermitContainer &data1, int n)> fun, Container &data, PermitContainer &data1, int n);

#endif //FUNCTIONALITIES_H