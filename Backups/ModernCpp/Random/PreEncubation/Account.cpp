#include "Account.h"
std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "_account_id: " << rhs._account_id
       << " _transaction_set: ";
       for(TransactionPointer tp : rhs._transaction_set){
        std::cout<<*tp<<" ";
       }
    os << " _account_balance: " << rhs._account_balance;
    return os;
}

Account::Account(std::string account_id, TransactionConatiner transaction_set, float account_balance)
        : _account_id{account_id}, _transaction_set{transaction_set}, _account_balance{account_balance} {}