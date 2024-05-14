#ifndef DATARECORD_H
#define DATARECORD_H

#include <vector>
#include <functional>
#include <memory>
#include <ostream>
#include "DataUnit.h"
using DataUnitPointer = std::shared_ptr<DataUnit>;

class DataRecord
{
private:
    std::vector<int> _data_values_provided;
    std::vector<int> _data_values_exprected;
    std::reference_wrapper<DataUnitPointer> _data_unit;
public:
    DataRecord()=default;
    DataRecord(const DataRecord &)=delete;
    DataRecord(DataRecord && )=delete;
    DataRecord & operator=(const DataRecord & )=delete;
    DataRecord &operator=(DataRecord &&)=delete;
    ~DataRecord()=default;
    DataRecord(std::vector<int> data_values_provided, std::vector<int> data_values_expected, std::reference_wrapper<DataUnitPointer> data_unit);

    std::vector<int> dataValuesProvided() const { return _data_values_provided; }
    void setDataValuesProvided(const std::vector<int> &data_values_provided) { _data_values_provided = data_values_provided; }

    std::vector<int> dataValuesExprected() const { return _data_values_exprected; }
    void setDataValuesExprected(const std::vector<int> &data_values_exprected) { _data_values_exprected = data_values_exprected; }

    std::reference_wrapper<DataUnitPointer> dataUnit() const { return _data_unit; }
    void setDataUnit(const std::reference_wrapper<DataUnitPointer> &data_unit) { _data_unit = data_unit; }

    friend std::ostream &operator<<(std::ostream &os, const DataRecord &rhs);
};

#endif // DATARECORD_H
