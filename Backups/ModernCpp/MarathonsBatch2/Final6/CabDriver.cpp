#include "CabDriver.h"
std::ostream &operator<<(std::ostream &os, const CabDriver &rhs) {
    os << "_name: " << rhs._name
       << " _km: " << rhs._km
       << " _price: " << rhs._price
       << " _company: " << rhs._company
       << " _car_type: ";
       if(rhs._car_type == CarType::HATCHBACK) os<<" Hatchback ";
       else if(rhs._car_type== CarType::SEDAN) os<<" Sedan ";
       else os<<" SUV ";
    os << " _total_wheels: " << rhs._total_wheels;
    return os;
}

CabDriver::CabDriver(std::string name, int km, float price, std::string company, CarType car_type, int total_wheels)
        : _name{name}, _km{km}, _price{price}, _company{company}, _car_type{car_type}, _total_wheels{total_wheels} {}