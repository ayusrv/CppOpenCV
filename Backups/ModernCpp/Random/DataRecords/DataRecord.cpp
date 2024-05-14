#include "DataRecord.h"
std::ostream &operator<<(std::ostream &os, const DataRecord &rhs) {
    os << "_data_values_provided: " ;
    for(int i :  rhs._data_values_provided){
        os<<i<<" ";
    }
    os<<std::endl;
    os << " _data_values_exprected: ";
    for(int i : rhs._data_values_exprected)
    {
        os<<i<<" ";
    }
    os<<std::endl;
    os  << " _data_unit: " << *rhs._data_unit.get()<<std::endl;
    return os;
}

DataRecord::DataRecord(std::vector<int> data_values_provided, std::vector<int> data_values_expected, std::reference_wrapper<DataUnitPointer> data_unit)
        : _data_values_provided{data_values_provided}, _data_values_exprected{data_values_expected}, _data_unit{data_unit} {}