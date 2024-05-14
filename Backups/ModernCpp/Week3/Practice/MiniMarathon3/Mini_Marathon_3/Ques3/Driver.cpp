#include "Driver.h"
std::ostream &operator<<(std::ostream &os, const Driver &rhs) {
    os << "_driver_id: " << rhs._driver_id
       << " _driver_rating: ";
       if(rhs._driver_rating==DriverRating::STAR_1) os<<"1 Star";
       else if(rhs._driver_rating==DriverRating::STAR_2) os<<"2 Star";
       else if(rhs._driver_rating==DriverRating::STAR_3) os<<"3 Star";
    return os;
}

Driver::Driver(std::string driver_id, DriverRating driver_rating)
        : _driver_id{driver_id}, _driver_rating{driver_rating} {}