#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Accounts.h"
#include <iostream>
#include <vector>

class Customer
{
private:
    std::string _name;
    std::string _dob;
    std::vector<Accounts*> _accounts;
    long _ph_no;
public:
    Customer(/* args */) {}
    ~Customer() {}
    Customer(std::string name, std::string dob, std::vector<Accounts*> account, long ph_no);

    long phNo() const { return _ph_no; }
    void setPhNo(long ph_no) { _ph_no = ph_no; }

    std::string dob() const { return _dob; }
    void setDob(const std::string &dob) { _dob = dob; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    std::vector<Accounts*> accounts() const { return _accounts; }
    void setAccounts(const std::vector<Accounts*> &accounts) { _accounts = accounts; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
    
};

#endif // CUSTOMER_H
