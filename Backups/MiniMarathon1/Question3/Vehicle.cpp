#include "Vehicle.h"

//Outputstream
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_registration_number: " << rhs._registration_number
       << " _brand: " << rhs._brand
       << " _price: " << rhs._price;
    return os;
}

//Parameterized constructor
Vehicle::Vehicle(std::string registration_number, std::string brand, float price)
        : _registration_number{registration_number}, _brand{brand}, _price{price} {}

//Calculating tax excepmtion
float Vehicle::TaxExcemptionAmount()
{   
    return (_price*5)/100;
}
