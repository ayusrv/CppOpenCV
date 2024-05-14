#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <memory>
#include <functional>
#include <list>

#include "SavingAccount.h"
#include "CurrentAccount.h"

using AccountPtr = std::shared_ptr<Account>;
using Container = std::list<AccountPtr>;

void CreateObject(Container& data);
bool checkDebitSaving(Container& data);
std::string maxBalance(Container& data);
DebitCard* getAccountData(Container& data, std::string account_number);
#endif // FUNCTIONALITIES_H
