#include "Accounts.h"
std::ostream &operator<<(std::ostream &os, const Accounts &rhs) {
    os << "_cheque: " << rhs._cheque
       << " _card_details: " << rhs._card_details
       << " _account_number: " << rhs._account_number
       <<" _balance: "<<rhs.balance();
    return os;
}

Accounts::Accounts(Cheque* cheque, CardDetails* card_details, long account_number, int balance)
        : _cheque(cheque), _card_details(card_details), _account_number(account_number), _balance(balance) {}

Accounts::Accounts(long account_number, int balance)
        : _account_number(account_number), _balance(balance) {}
