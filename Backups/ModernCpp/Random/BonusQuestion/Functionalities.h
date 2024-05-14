#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Teacher.h"
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <numeric>
#include <queue>

using TeacherPointer = std::shared_ptr<Teacher>;
using Container = std::unordered_map<std::string, TeacherPointer>;
using PairVal = std::pair<std::string, TeacherPointer>;
using PriorityQueue = std::priority_queue<PairVal, std::vector<PairVal>, std::function<bool(const PairVal& p1, const PairVal& p2)>>;

extern std::function<void(Container&)> CreateObject;
extern std::function<void(Container&)> Display;
extern std::function<bool(VType&)> Percentage;
extern std::function<void(Container&)> PassFaill;
extern std::function<TeacherPointer(Container&)> MaxMarks;
extern std::function<void(Container&)> Priorities;

#endif // FUNCTIONALITIES_H
