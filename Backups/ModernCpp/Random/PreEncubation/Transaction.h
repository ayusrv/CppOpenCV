#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "TranscationType.h"

class Transaction
{
private:

    std::string _transaction_id;
    float _transaction_amount;
    TransactionType _transaction_type;

public:

    Transaction()=default;
    Transaction(const Transaction &)=delete;
    Transaction(Transaction && )=delete;
    Transaction & operator=(const Transaction & )=delete;
    Transaction &operator=(Transaction &&)=delete;
    ~Transaction()=default;
    Transaction(std::string transaction_id, float transaction_amount, TransactionType transaction_type);

    std::string transactionId() const { return _transaction_id; }
    void setTransactionId(const std::string &transaction_id) { _transaction_id = transaction_id; }

    float transactionAmount() const { return _transaction_amount; }
    void setTransactionAmount(float transaction_amount) { _transaction_amount = transaction_amount; }

    TransactionType transactionType() const { return _transaction_type; }
    void setTransactionType(const TransactionType &transaction_type) { _transaction_type = transaction_type; }

    friend std::ostream &operator<<(std::ostream &os, const Transaction &rhs);
    
};

#endif // TRANSACTION_H
