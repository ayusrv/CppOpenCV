#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "Employee.h"
#include "EmptyContainer.h"
#include "BussinessOwner.h"
#include <variant>
#include <memory>
#include <vector>
#include <ostream>

using BussinessPointer = std::shared_ptr<BussinessOwner>;
using EmployeePointer = std::shared_ptr<Employee>;
using VType = std::variant<BussinessPointer, EmployeePointer>;
class DataModel
{
private:
    VType _instances;       
    std::vector<float> _prices;

public:
    DataModel()=default;
    DataModel(const DataModel &)=delete;
    DataModel(DataModel && )=delete;
    DataModel & operator=(const DataModel & )=delete;
    DataModel &operator=(DataModel &&)=delete;
    ~DataModel()=default;
    DataModel(VType instances, std::vector<float> prices);
    void operator()();

    VType instances() const { return _instances; }
    void setInstances(const VType &instances) { _instances = instances; }

    std::vector<float> prices() const { return _prices; }
    void setPrices(const std::vector<float> &prices) { _prices = prices; }

    friend std::ostream &operator<<(std::ostream &os, const DataModel &rhs);
};

#endif // DATAMODEL_H
