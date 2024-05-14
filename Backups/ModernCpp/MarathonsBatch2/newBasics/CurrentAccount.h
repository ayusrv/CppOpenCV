#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"
#include <ostream>

class CurrentAccount : public Account
{
private:
    bool _m_bussiness_load_applied;
public:
    CurrentAccount()=default;
    CurrentAccount(const CurrentAccount &)=delete;
    CurrentAccount(CurrentAccount && )=delete;
    CurrentAccount & operator=(const CurrentAccount & )=delete;
    CurrentAccount &operator=(CurrentAccount &&)=delete;
    ~CurrentAccount()=default;
    CurrentAccount(std::string date, long card_number, int cvv, std::string m_account_number, float m_account_balance, std::string m_account_holder_name, DebitCard* m_debit_card, bool m_bussiness_applied);

    float CalculateAnnualCharges();

    bool mBussinessLoadApplied() const { return _m_bussiness_load_applied; }
    void setMBussinessLoadApplied(bool m_bussiness_load_applied) { _m_bussiness_load_applied = m_bussiness_load_applied; }

    friend std::ostream &operator<<(std::ostream &os, const CurrentAccount &rhs);
};

#endif // CURRENTACCOUNT_H
