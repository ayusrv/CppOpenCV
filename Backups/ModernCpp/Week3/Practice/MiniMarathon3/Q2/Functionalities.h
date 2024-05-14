#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <array>
#include <future>
#include <memory>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include "Car.h"
#include "EmptyContainerException.h"
#include "TyrePressureExceed.h"
#include "IdNotFound.h"

using CarPointer = std::shared_ptr<Car>;
using Container = std::array<CarPointer, 3>;
using MapContainer = std::unordered_map<std::string, CarPointer>;

void CreateObject(MapContainer& data);

MapContainer PriceThreshold(MapContainer& data, float price);

CarPointer CarFound(MapContainer& data, std::string chassis_number);

MapContainer CategoryMatch(MapContainer& data, Category car_type);

std::array<float,4> AveragePrice(MapContainer& data);

bool CheckPressure(MapContainer& data);

#endif // FUNCTIONALITIES_H
