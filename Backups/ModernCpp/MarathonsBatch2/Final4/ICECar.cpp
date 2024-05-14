#include "ICECar.h"
std::ostream &operator<<(std::ostream &os, const ICECar &rhs) {
    os << "_id: " << rhs._id
       << " _brand_name: " << rhs._brand_name
       << " _price: " << rhs._price
       << " _engine_type: ";
       if(rhs._engine_type == EngineType::DIESEL) os<<" Diesel ";
       else os<<" Petrol ";
    return os;
}

ICECar::ICECar(std::string id, std::string brand_name, float price, EngineType engine_type)
       : _id{id}, _brand_name{brand_name}, _price{price}, _engine_type{engine_type} {}

float ICECar::CalculateRegistrationCharges()
{
    if(this->engineType() == EngineType::DIESEL)
    {
        return 0.13*this->price();
    }
    else{
        return 0.10*this->price();
    }
}
