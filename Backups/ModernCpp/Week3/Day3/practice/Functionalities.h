#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "DataModel.h"
#include<future>
#include <functional>

using DataPointer = std::shared_ptr<DataModel>;
using Container = std::vector<DataPointer>;
using FType = std::function<void(Container&)>;

extern FType CreateObject;
extern FType CalculateTaxPayable;
extern FType CallParentOperator;
extern std::function<int(Container&, std::future<int>&)> GetData;

#endif // FUNCTIONALITIES_H
