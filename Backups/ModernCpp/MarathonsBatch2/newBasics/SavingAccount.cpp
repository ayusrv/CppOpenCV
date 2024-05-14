#include "SavingAccount.h"
std::ostream &operator<<(std::ostream &os, const SavingAccount &rhs) {
    os << static_cast<const Account &>(rhs)
       << " _m_account_balance: " << rhs._m_account_balance;
    return os;
}

SavingAccount::SavingAccount(std::string date, long card_number, int cvv, std::string m_account_number, float m_account_balance, std::string m_account_holder_name, DebitCard *m_debit_card, float min_account_balance)
        : Account(date, card_number, cvv, m_account_number, m_account_balance, m_account_holder_name, m_debit_card), _m_account_balance{min_account_balance} {}
float SavingAccount::CalculateAnnualCharges()
{
    if(this->mDebitCard()){
        this->_m_account_balance = 500.0f;
    }
    else{
        this->_m_account_balance = 100.0f;
    }
    return 0.0f;
}
