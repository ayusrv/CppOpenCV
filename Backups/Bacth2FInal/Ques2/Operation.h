#ifndef OPERATION_H
#define OPERATION_H

#include <vector>
#include <memory>
#include <numeric>
#include <algorithm>
#include "Car.h"
#include "EmptyConatinerException.h"

class Operation;
using EngineConatiner = std::vector<Engine>;
using CarPointer = std::shared_ptr<Car>;
using Container = std::vector<CarPointer>;
using OperationPointer = std::unique_ptr<Operation>;

class Operation
{
private:
    static OperationPointer _solo_hero_obj;
    Operation() = default;
    Operation(const Operation &)=delete;
    Operation(Operation && )=delete;
    Operation & operator=(const Operation & )=delete;
    Operation &operator=(Operation &&)=delete;
public:
    ~Operation()=default;
    static OperationPointer& getInstance();
    void CreateObject(Container& data, EngineConatiner& ec);
    std::vector<std::reference_wrapper<Engine>> getEngine(Container& data);
    bool engineTorque(Container& data);
    float averageHorsePower(Container& data, float price);
    EngineType findEngineType(Container& data, std::string reg_num);
    std::reference_wrapper<Engine> highestTorque(Container& data);
};

#endif // OPERATION_H