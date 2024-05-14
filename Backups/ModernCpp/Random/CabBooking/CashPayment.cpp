#include "CashPayment.h"
std::ostream &operator<<(std::ostream &os, const CashPayment &rhs) {
    os << static_cast<const CabBooking &>(rhs) <<std::endl
       << " _reward_points: " << rhs._reward_points <<std::endl;
    return os;
}

CashPayment::CashPayment(std::string booking_id, std::string pickup_location, std::string drop_location, float base_fare, unsigned int reward_points)
            : CabBooking(booking_id, pickup_location, drop_location, base_fare), _reward_points{reward_points} {}

float CashPayment::CabFareCalculation()
{
    float total_fare = 0.0f;
    if(rewardPoints() < ((baseFare()*25)/100)){
        total_fare =  2*baseFare();
    }else{
        total_fare = 1.5*baseFare();
    }
    return total_fare;
}