#include "DataUnit.h"
std::ostream &operator<<(std::ostream &os, const DataUnit &rhs) {
    os << "_unit_id: " << rhs._unit_id
       << " _unit_type: ";

    if(rhs._unit_type==UnityType::IN_HOUSE) os<<"In house ";
    else os<<"Outsourced ";

    os << " _unit_reading: " << rhs._unit_reading <<std::endl;
    return os;
}

DataUnit::DataUnit(int unit_id, UnityType unit_type, float unit_reading)
        : _unit_id{unit_id}, _unit_type{unit_type}, _unit_reading{unit_reading} {}