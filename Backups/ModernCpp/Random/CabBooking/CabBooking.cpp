#include "CabBooking.h"
std::ostream &operator<<(std::ostream &os, const CabBooking &rhs) {
    os << "_booking_id: " << rhs._booking_id
       << " _pickup_location: " << rhs._pickup_location
       << " _drop_location: " << rhs._drop_location
       << " _base_fare: " << rhs._base_fare;
    return os;
}

CabBooking::CabBooking(std::string booking_id, std::string pickup_location, std::string drop_location, float base_fare)
            : _booking_id{booking_id}, _base_fare{base_fare}, _pickup_location{pickup_location}, _drop_location{drop_location} {}