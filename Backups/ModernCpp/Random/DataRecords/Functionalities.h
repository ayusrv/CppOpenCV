#include <numeric>
#include <algorithm>
#include "DataRecord.h"

using DataRecordPointer = std::shared_ptr<DataRecord>;
using UnitContainer = std::vector<DataUnitPointer>;
using Container = std::vector<DataRecordPointer>;
using FType = std::function<void(Container&)>;

void createObject(Container& data, UnitContainer& data2);

extern FType PrintCertainData;
extern FType PrintMaximum;
extern FType getOdd;

void HighOrder(Container& data, FType &fn);