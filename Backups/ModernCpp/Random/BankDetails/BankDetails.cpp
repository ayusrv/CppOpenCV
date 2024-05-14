#include "BankDetails.h"

BankDetails::BankDetails(std::string bank_name, std::string bank_city, std::string bank_ifsc, std::vector<Customer *> customer)
            : _bank_name{bank_name}, _bank_city{bank_city}, _bank_ifsc{bank_ifsc} {
                for(Customer* c : customer){
                    _customer.push_back(c);
                }
            }

std::ostream &operator<<(std::ostream &os, const BankDetails &rhs) {
    os << "_bank_name: " << rhs._bank_name
       << " _bank_city: " << rhs._bank_city
       << " _bank_ifsc: " << rhs._bank_ifsc;
    //    << " _customer: " << rhs._customer;
    return os;
}
