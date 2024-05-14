#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Account.h"
#include <algorithm>
#include <numeric>
#include <functional>
#include <optional>
#include <future>
#include <thread>
#include <mutex>

using AccountPointer = std::shared_ptr<Account>;
using Container = std::vector<AccountPointer>;

extern std::function<void(Container&)> CreateObject;
extern std::function<int(Container&, TransactionType)> CountTransactionOfGivenType;
extern std::function<float(Container&)> TotalTransactionAmount;
extern std::function<float(Container&, TransactionType)> FindMaxAccountBalance;
extern std::function<std::optional<Container>(Container&,float)> AccountAboveThreshold;
extern std::function<std::string(Container&, int)> NthTransactionId;
extern std::function<float(Container&)> AverageTransactionAmount;
float calculateTax(AccountPointer data);
extern std::function<void(Container&)> BalanceInterest;


#endif // FUNCTIONALITIES_H 