#include "Car.h"
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_brand_name: " << rhs._brand_name
       << " _chassis_number: " << rhs._chassis_number
       << " _category: ";
       if(rhs._category==Category::COMMUTE) os<<"Commute ";
       else if(rhs._category==Category::SPORTS) os<<"Sports ";
        else os<<"Tourist ";
    os << " _price: " << rhs._price
       << " _tyre_rim_sime: ";
       if(rhs._tyre_rim_size==::RimSize::INCH_14) os<<"14_Inch ";
       else if(rhs._tyre_rim_size==RimSize::INCH_15) os<<"15_Inch";
       else if(rhs._tyre_rim_size==RimSize::INCH_16) os<<"16_Inch";
       else os<<"18_Inch ";
    os << " _expected_tyre_pressure: " << rhs._expected_tyre_pressure;
    return os;
}

Car::Car(std::string brand_name, std::string chassis_number, Category category, float price, RimSize tyre_rim_size, int expected_tyre_pressure)
        : _brand_name{brand_name}, _chassis_number{chassis_number}, _category{category}, _price{price}, _tyre_rim_size{tyre_rim_size} {}