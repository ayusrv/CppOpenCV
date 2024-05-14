#include "Cab.h"
std::ostream &operator<<(std::ostream &os, const Cab &rhs) {
    os << "_id: " 
       << " _fare: " << rhs._fare
       << " _pickup_location: " << rhs._pickup_location
       << " _drop_location: " << rhs._drop_location;
    return os;
}

Cab::Cab(VType id, RideType ride_type, PaymentMode payment_mode, float fare, std::string pickup_location, std::string drop_location, DriverReference cab_driver)
    : _id{std::ref(id)}, _ride_type{ride_type}, _payment_mode{payment_mode}, _fare{fare}, _pickup_location{pickup_location}, _drop_location{drop_location}, _cab_driver{cab_driver} {}