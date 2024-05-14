#include "Car.h"

//Output Stream
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << static_cast<const Vehicle &>(rhs);
    os    << " _type: ";
    if(rhs._type == CarType::COMERCIAL)
        os<<"Comercial";
    else if(rhs._type == CarType::COMMUTE)
        os<<"Commute";
    else 
        os<<"Transport";
    return os;
}

//Parameterized Constructor
Car::Car(std::string registration_number, std::string brand, float price, CarType type)
        : Vehicle(registration_number, brand, price), _type{type} {}

//Calculate Serevice Cost
float Car::CalculateServicingCost()
{
    return (price()*8)/100;
}

//TAX ExcemptionAMount
float Car::TaxExcemptionAmount()
{
    if(type() == CarType::COMMUTE){
        return (price()*20)/100;
    }else{
        return (price()*15)/100;
    }
}
