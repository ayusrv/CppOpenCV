#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "School.h"
#include <vector>
#include <functional>
#include <optional>
#include <future>

using SType = std::shared_ptr<School>;
using Container = std::vector<SType>;

extern std::function<void(Container&)> CreateObject;
extern std::function<float(Container&)> AverageAge;
extern std::function<std::optional<std::vector<std::string>>(Container&)> SameTeacher;
extern std::function<std::future<int(Container&)>> SalaryThreshold;
extern std::function<void(Container&, int)> NInstances;

#endif // FUNCTIONALITIES_H
