#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "EvCar.h"
#include <vector>
#include <list>
#include <memory>
#include <optional>
#include <algorithm>
#include <numeric>

using EvCarPointer = std::shared_ptr<EvCar>;
using Container = std::vector<EvCarPointer>;

void CreateObject(Container& data);
std::optional<std::list<EvCarPointer>> NInsatances(Container& data, int n);
int CountInstances(Container& data);
int TopSpeed(Container& data, std::string m_car_id);
bool PureEvPlatform(Container& data);

#endif // FUNCTIONALITIES_H
