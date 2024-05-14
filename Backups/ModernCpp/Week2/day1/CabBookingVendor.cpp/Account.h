/*
    _id,
    _username
    static counter

    disabel all special member except destructor
    <<out operator
    pure virtual register account
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
class Account
{
private:
    unsigned long _userId;
    static unsigned long _counter;
    std::string _username;
public:
    Account() = delete;
    Account(const Account&) = delete;
    Account(const Account &&) = delete;
    Account& operator = (const Account&&) = delete;
    Account& operator = (const Account&) = delete;
    ~Account() = default;
    explicit Account(std::string username);

    virtual void RegisterAccount() = 0;

    std::string username() const { return _username; }
    void setUsername(const std::string &username) { _username = username; }

    unsigned long userId() const { return _userId; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

};


#endif // ACCOUNT_H
