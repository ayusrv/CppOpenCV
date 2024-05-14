#include "CurrentAccount.h"
std::ostream &operator<<(std::ostream &os, const CurrentAccount &rhs) {
    os << "_m_bussiness_load_applied: " << rhs._m_bussiness_load_applied;
    return os;
}

CurrentAccount::CurrentAccount(std::string date, long card_number, int cvv, std::string m_account_number, float m_account_balance, std::string m_account_holder_name, DebitCard *m_debit_card, bool m_bussiness_applied)
        : Account(date, card_number, cvv, m_account_number, m_account_balance, m_account_holder_name, m_debit_card), _m_bussiness_load_applied{m_bussiness_applied} {}

float CurrentAccount::CalculateAnnualCharges()
{
    return 800.0f;
}
