#include "TouristVehicle.h"
std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    os << "_number: " << rhs._number
       << " _vehicle_type: ";
    if(rhs._vehicle_type == VehicleType::BIKE){
        os<<"BIKE";
    }
    else if(rhs._vehicle_type == VehicleType::BUS){
        os<<"BUS";
    }
    else{
        os<<"CAB";
    }
    os << " _sert_count: " << rhs._seat_count
       << " _per_hour_booking_charge: " << rhs._per_hour_booking_charge 
       <<" _permit "<<rhs._permit;
    return os;
}

TouristVehicle::TouristVehicle(std::string number, VehicleType vehicle_type, int seat_count, float per_hour_booking_charge, std::reference_wrapper<Permit> permit)
                : _number{number}, _vehicle_type{vehicle_type}, _seat_count{seat_count}, _per_hour_booking_charge{per_hour_booking_charge}, _permit{permit} {}

