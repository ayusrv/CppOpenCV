#include "Account.h"

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "_m_account_number: " << rhs._m_account_number
       << " _m_account_balance: " << rhs._m_account_balance
       << " _m_account_holder_name: " << rhs._m_account_holder_name
       << " _m_debit_card: " << rhs._m_debit_card;
    return os;
}

Account::Account(std::string date, long card_number, int cvv, std::string m_account_number, float m_account_balance, std::string m_account_holder_name, DebitCard *m_debit_card)
        : _m_account_number{m_account_number}, _m_account_balance{m_account_balance}, _m_account_holder_name{m_account_holder_name} {
            _m_debit_card = new DebitCard(date, card_number, cvv);
        }
