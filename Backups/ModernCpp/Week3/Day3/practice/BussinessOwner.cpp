#include "BussinessOwner.h"
std::ostream &operator<<(std::ostream &os, const BussinessOwner &rhs) {
    os << "_expenses: " << rhs._expenses
       << " _revenue: " << rhs._revenue
       << " _registered_bussiness_name: " << rhs._registered_bussiness_name
       << " _bussiness_type: ";
       if(rhs._bussiness_type == BussinessType::MNC) os<<"MNC";
       else os<<"SME";
    return os;
}

BussinessOwner::BussinessOwner(float expenses, float revenue, std::string registered_bussiness_type, BussinessType bussiness_type)
                : _expenses{expenses}, _revenue{revenue}, _registered_bussiness_name{_registered_bussiness_name}, _bussiness_type{bussiness_type} {}