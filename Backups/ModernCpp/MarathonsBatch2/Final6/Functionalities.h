#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <queue>
#include <unordered_set>
#include <functional>
#include <memory>
#include <vector>
#include <optional>

#include "CabDriver.h"
#include "EmptyContainerException.h"

using CabDriverPtr = std::shared_ptr<CabDriver>;
using Container = std::vector<CabDriverPtr>;
using PriorityQueue = std::priority_queue<CabDriverPtr, std::vector<CabDriverPtr>, std::function<bool(CabDriverPtr& cp1, CabDriverPtr& cp2)>>;

void CreateObject(Container& data);
std::optional<std::unordered_set<CabDriverPtr>> getFunctions(Container& data, std::vector<std::function<bool(const CabDriverPtr cp1)>> functions);
void checkPair(Container& data, std::pair<std::string, int>& pr, int n);
PriorityQueue PriorityValues(Container& data, std::function<bool(CabDriverPtr& cp1, CabDriverPtr& cp2)>);

#endif // FUNCTIONALITIES_H