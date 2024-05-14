#ifndef DATAUNIT_H
#define DATAUNIT_H

#include <iostream>
#include "UnitType.h"

class DataUnit
{
private:
    int _unit_id;
    UnityType _unit_type;
    float _unit_reading;

public:
    DataUnit()=default;
    DataUnit(const DataUnit &)=delete;
    DataUnit(DataUnit && )=delete;
    DataUnit & operator=(const DataUnit & )=delete;
    DataUnit &operator=(DataUnit &&)=delete;
    ~DataUnit()=default;
    DataUnit(int unit_id, UnityType unit_type, float unit_reading);

    int unitId() const { return _unit_id; }
    void setUnitId(int unit_id) { _unit_id = unit_id; }

    UnityType unitType() const { return _unit_type; }
    void setUnitType(const UnityType &unit_type) { _unit_type = unit_type; }

    float unitReading() const { return _unit_reading; }
    void setUnitReading(float unit_reading) { _unit_reading = unit_reading; }

    friend std::ostream &operator<<(std::ostream &os, const DataUnit &rhs);
};

#endif // DATAUNIT_H
