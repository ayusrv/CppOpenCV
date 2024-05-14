#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <list>
#include <unordered_map>
#include <queue>
#include <memory>
#include <array>
#include <unordered_set>
#include <future>
#include <numeric>
#include <algorithm>

#include "EmptyContainerException.h"
#include "SizeExceed.h"
#include "Vehicle.h"

using VehiclePtr = std::shared_ptr<Vehicle>;
using Conatiner = std::list<VehiclePtr>;
using PriorityQueue = std::priority_queue<VehiclePtr, std::vector<VehiclePtr>, std::function<bool(VehiclePtr vp1, VehiclePtr vp2)>>;

void CreateObject(Conatiner& data);
TransmissionType* getTransmission(Conatiner& data, int n);
PriorityQueue getPriority(Conatiner& data, std::function<bool(VehiclePtr vp1, VehiclePtr vp2)> fun);
std::unordered_set<float> getPrice(Conatiner& data);
std::unordered_map<std::string, VehicleCategory> getCategory(Conatiner& data, std::future<int>& fut);
Conatiner transformData(Conatiner& data);


#endif // FUNCTIONALITIES_H
