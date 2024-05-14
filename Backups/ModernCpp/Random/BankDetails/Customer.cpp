#include "Customer.h"

Customer::Customer(std::string name, std::string dob, std::vector<Accounts*> account, long ph_no)
        : _name{name}, _dob{dob}, _ph_no{ph_no} {
            for(Accounts* a : account){
                _accounts.push_back(a);
            }
        }

std::ostream &operator<<(std::ostream &os, const Customer &rhs) {
    os << "_name: " << rhs._name
       << " _dob: " << rhs._dob
       << " _ph_no: " << rhs._ph_no;
    return os;
}

