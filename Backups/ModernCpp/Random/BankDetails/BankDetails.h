#ifndef BANKDETAILS_H
#define BANKDETAILS_H

#include "Customer.h"
#include <iostream>
#include <vector>

class BankDetails
{
private:
    std::string _bank_name;
    std::string _bank_city;
    std::string _bank_ifsc;
    std::vector<Customer*> _customer;
public:
    BankDetails(/* args */) {}
    ~BankDetails() {}

    BankDetails(std::string bank_name, std::string bank_city, std::string bank_ifsc, std::vector<Customer*> customer);

    std::string bankIfsc() const { return _bank_ifsc; }
    void setBankIfsc(const std::string &bank_ifsc) { _bank_ifsc = bank_ifsc; }

    std::string bankCity() const { return _bank_city; }
    void setBankCity(const std::string &bank_city) { _bank_city = bank_city; }

    std::string bankName() const { return _bank_name; }
    void setBankName(const std::string &bank_name) { _bank_name = bank_name; }

    std::vector<Customer*> customer() const { return _customer; }
    void setCustomer(const std::vector<Customer*> &customer) { _customer = customer; }

    friend std::ostream &operator<<(std::ostream &os, const BankDetails &rhs);
};

#endif // BANKDETAILS_H
