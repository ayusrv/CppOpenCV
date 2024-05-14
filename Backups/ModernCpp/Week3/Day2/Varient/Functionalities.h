#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "ElectricVehicle.h"
#include "Diesel.h"
#include <vector>
#include<functional>
#include <variant>
#include <memory>


using VType = std::variant<std::shared_ptr<Diesel>, std::shared_ptr<ElectricVehicle>>;
using Container = std::vector<VType>;

using FnType=std::function<void(Container&)>;

extern FnType CreateObjects;
extern FnType DisplayObjects;
extern FnType DriveData;

#endif // FUNCTIONALITIES_H
