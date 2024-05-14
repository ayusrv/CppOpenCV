#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Bike.h"
#include "Car.h"
#include <memory>
#include <vector>
#include <algorithm>
#include "EmptyContainerException.h"

//Pointer of shared pointer for vehicle
using Pointer = std::shared_ptr<Vehicle>;

//Container for storing Pointer
using Container = std::vector<Pointer>;

void CreateObject(Container &data);
void DisplayObject(Container &data);
void PrintCalculateServicingCost(Container &data);
void PrintTaxExcemption(Container &data);
void PrintVehicleObject(Container &data, std::string registration_number);


#endif // FUNCTIONALITIES_H
