#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <variant>
#include <memory>
#include <functional>
#include <numeric>
#include <unordered_set>
#include <algorithm>

#include "EvCar.h"
#include "ICECar.h"
#include "EmptyConatinerException.h"

using EvCarPtr = std::shared_ptr<EvCar>;
using ICECarPtr = std::shared_ptr<ICECar>;
using VType = std::variant<EvCarPtr, ICECarPtr>;
using Conatiner = std::vector<VType>;

extern std::function<void(Conatiner& data)> CreateObject;
extern std::function<Conatiner(Conatiner& data)> FindInstances;
extern std::function<float(Conatiner& data)> AveragePrice;
extern std::function<int(Conatiner& data, EPowerType engine_type)> CountEvCar;
extern std::function<std::string(Conatiner& data, std::string id)> FindName;
extern std::function<std::unordered_set<EPowerType>(Conatiner& data)> FindBattery;
extern std::function<bool(Conatiner& data)> CheckPrice;

#endif // FUNCTIONALITIES_H
