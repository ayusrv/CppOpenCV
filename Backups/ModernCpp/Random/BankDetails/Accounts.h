#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "CardDetails.h"
#include "Cheque.h"
#include <iostream>

class Accounts
{
    private:
        Cheque* _cheque;
        CardDetails* _card_details;
        int _balance;
        long _account_number;
    public:
        Accounts(Cheque* cheque, CardDetails* card_details, long account_number, int balance);
        Accounts(long account_number, int balance);

        Cheque* cheque() const { return _cheque; }

        long accountNumber() const { return _account_number; }
        void setAccountNumber(long account_number) { _account_number = account_number; }

        void setCheque(Cheque* cheque) { _cheque = cheque; }

        CardDetails* cardDetails() const { return _card_details; }
        void setCardDetails(CardDetails* card_details) { _card_details = card_details; }

        int balance() const { return _balance; }
        void setBalance(int balance) { _balance = balance; }

        friend std::ostream &operator<<(std::ostream &os, const Accounts &rhs);
        
};

#endif // ACCOUNTS_H
