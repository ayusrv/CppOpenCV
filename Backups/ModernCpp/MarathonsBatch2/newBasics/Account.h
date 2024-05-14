#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "DebitCard.h"
#include <ostream>

class Account
{
private:
    std::string _m_account_number;
    float _m_account_balance;
    std::string _m_account_holder_name;
    DebitCard* _m_debit_card;
public:
    Account()=default;
    Account(const Account &)=delete;
    Account(Account && )=delete;
    Account & operator=(const Account & )=delete;
    Account &operator=(Account &&)=delete;
    ~Account()=default;
    Account(std::string date, long card_number, int cvv, std::string m_account_number, float m_account_balance, std::string m_account_holder_name, DebitCard* m_debit_card);

    virtual float CalculateAnnualCharges() = 0;

    DebitCard* mDebitCard() const { return _m_debit_card; }
    void setMDebitCard(DebitCard* m_debit_card) { _m_debit_card = m_debit_card; }

    std::string mAccountHolderName() const { return _m_account_holder_name; }
    void setMAccountHolderName(const std::string &m_account_holder_name) { _m_account_holder_name = m_account_holder_name; }

    float mAccountBalance() const { return _m_account_balance; }
    void setMAccountBalance(float m_account_balance) { _m_account_balance = m_account_balance; }

    std::string mAccountNumber() const { return _m_account_number; }
    void setMAccountNumber(const std::string &m_account_number) { _m_account_number = m_account_number; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

#endif // ACCOUNT_H
