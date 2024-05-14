#include "Transaction.h"
std::ostream &operator<<(std::ostream &os, const Transaction &rhs) {
    os << "_transaction_id: " << rhs._transaction_id
       << " _transaction_amount: " << rhs._transaction_amount
       << " _transaction_type: ";
       if(rhs._transaction_type == TransactionType::CARD) os<<"Card ";
       else if(rhs._transaction_type==TransactionType::CASH) os<<"Cash ";
       else os<<"UPI ";
    return os;
}

Transaction::Transaction(std::string transaction_id, float transaction_amount, TransactionType transaction_type)
            : _transaction_id{transaction_id}, _transaction_amount{transaction_amount}, _transaction_type{transaction_type} {}