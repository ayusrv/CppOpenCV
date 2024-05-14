#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include <vector>
#include <memory>
#include <ostream>

using TransactionPointer = std::shared_ptr<Transaction>;
using TransactionConatiner = std::vector<TransactionPointer>;

class Account
{
private:
    
    std::string _account_id;
    TransactionConatiner _transaction_set;
    float _account_balance;

public:
    Account()=default;
    Account(const Account &)=delete;
    Account(Account && )=delete;
    Account & operator=(const Account & )=delete;
    Account &operator=(Account &&)=delete;
    ~Account()=default;
    Account(std::string account_id, TransactionConatiner transaction_set, float account_balance);

    std::string accountId() const { return _account_id; }
    void setAccountId(const std::string &account_id) { _account_id = account_id; }

    TransactionConatiner transactionSet() const { return _transaction_set; }
    void setTransactionSet(const TransactionConatiner &transaction_set) { _transaction_set = transaction_set; }

    float accountBalance() const { return _account_balance; }
    void setAccountBalance(float account_balance) { _account_balance = account_balance; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
    
};

#endif // ACCOUNT_H
