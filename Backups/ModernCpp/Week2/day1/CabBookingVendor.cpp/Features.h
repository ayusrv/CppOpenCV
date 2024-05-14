#ifndef FEATURES_H
#define FEATURES_H

#include "Account.h"
#include "Enums.h"
#include <vector>
using AccountContainer = std::vector<Account *>;

class Features
{
private:
public:
    Features(/* args */) {}
    ~Features() {}

    /*
        Should accept reference of a container,
        an enum to decide type of account,
        then accept input to call the corret constructor
        store pointer in accountsContainer
    */

   static void CreateObject(AccountContainer& account, AccountType accountType);
};
#endif // FEATURES_H
