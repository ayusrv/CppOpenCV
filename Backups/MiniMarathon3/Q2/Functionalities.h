#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <array>
#include <future>
#include <memory>
#include <functional>
#include <vector>
#include "Car.h"
#include "EmptyContainerException.h"
#include "TyrePressureExceed.h"
#include "IdNotFound.h"

using CarPointer = std::shared_ptr<Car>;
using Container = std::array<CarPointer, 3>;

void CreateObject(Container& data);

std::vector<CarPointer> PriceThreshold(Container& data, float price);

CarPointer CarFound(Container& data, std::string chassis_number);

std::vector<CarPointer> CategoryMatch(Container& data, Category car_type);

std::array<float,4> AveragePrice(Container& data);

bool CheckPressure(Container& data);

#endif // FUNCTIONALITIES_H
