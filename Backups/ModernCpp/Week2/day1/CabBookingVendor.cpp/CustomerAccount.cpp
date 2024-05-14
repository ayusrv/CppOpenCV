#include "CustomerAccount.h"

CustomerAccount::CustomerAccount(std::string name, std::string fullname, Gender cGender)
        : Account(name) {
            _fullname = fullname, _customerGender = cGender;
        }
void CustomerAccount::RegisterAccount()
{
    std::cout<<"Account verified via OTP";
}

std::ostream &operator<<(std::ostream &os, const CustomerAccount &rhs)
{

    os << "_fullname: " << rhs._fullname;
    if (rhs._customerGender == Gender::MALE)
    {
        os << "_customerGender: Male" << std::endl;
    }
    else if (rhs._customerGender == Gender::OTHER)
    {
        os << "_customerGender: Other" << std::endl;
    }
    else
    {
        os << "_customerGender: Female" << std::endl;
    }
    return os;
}

