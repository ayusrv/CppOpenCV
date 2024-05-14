#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "Account.h"
#include <ostream>

class SavingAccount : public Account
{
private:
    float _m_account_balance;
public:
    SavingAccount()=default;
    SavingAccount(const SavingAccount &)=delete;
    SavingAccount(SavingAccount && )=delete;
    SavingAccount & operator=(const SavingAccount & )=delete;
    SavingAccount &operator=(SavingAccount &&)=delete;
    ~SavingAccount()=default;
    SavingAccount(std::string date, long card_number, int cvv, std::string m_account_number, float m_account_balance, std::string m_account_holder_name, DebitCard* m_debit_card, float min_account_balance);
    
    float CalculateAnnualCharges();

    float mAccountBalance() const { return _m_account_balance; }
    void setMAccountBalance(float m_account_balance) { _m_account_balance = m_account_balance; }

    friend std::ostream &operator<<(std::ostream &os, const SavingAccount &rhs);
};

#endif // SAVINGACCOUNT_H
