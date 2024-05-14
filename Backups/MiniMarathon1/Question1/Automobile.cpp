#include "Automobile.h"

std::ostream &operator<<(std::ostream &os, const Automobile &rhs) {
    os << "_model_name: " << rhs._model_name;
    if(rhs._automobile_type==AutomobileType::PRIVATE){
        os<<" _automobile_type: Private";
    }else{
        os<<" _automoble_type: Transport";
    }
    os   << " _automobile_price: " << rhs._automobile_price
       << " _automobile_milage: " << rhs._automobile_milage;
    return os;
}

Automobile::Automobile(std::string model_name, AutomobileType automobile_type, float automobile_price, float automobile_milage)
            : _model_name{model_name}, _automobile_type{automobile_type}, _automobile_price{automobile_price}, _automobile_milage{automobile_milage} {}