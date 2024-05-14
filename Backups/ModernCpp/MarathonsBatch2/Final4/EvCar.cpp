#include "EvCar.h"
std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << "_id: " << rhs._id
       << " _brand_name: " << rhs._brand_name
       << " _price: " << rhs._price
       << " _engine_type: ";
       if(rhs._engine_type == EPowerType::ELECTRIC) os<<" Electric ";
       else os<<" Hybrid ";

    os << " _battery_type: ";
    if(rhs._battery_type==BatteryType::LI_ON) os<<" LI_ON ";
    else if(rhs._battery_type==BatteryType::NICAD) os<<" NICAD ";
    else os<<" Other ";
    return os;
}

EvCar::EvCar(std::string id, std::string brand_name, float price, EPowerType engine_type, BatteryType battery_type)
        : _id{id}, _brand_name{brand_name}, _price{price}, _engine_type{engine_type}, _battery_type{battery_type} {}

float EvCar::CalculateRegistrationCharges()
{
    if(this->engineType() == EPowerType::ELECTRIC)
    {
        return 0.5*this->price();
    }
    else{
        return 0.6*this->price();
    }
}
