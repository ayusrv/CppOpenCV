#include "OnlinePayment.h"
std::string OnlinePayment::PaymentTypeConverter(PaymentType payment)
{
    switch (payment)
    {
    case PaymentType::CARD :
        return "Card";

    case PaymentType::ONLINE_WALLET : 
        return "Online Wallet";
    
    case PaymentType::UPI :
        return "UPI";
    
    default:
        return std::string();
    }

    return std::string();
}

float OnlinePayment::CabFareCalculation()
{
    float total_fare = 0.0f;
    if(payment()==PaymentType::CARD || payment()==PaymentType::UPI){
        total_fare = baseFare() * dropCounts();
    }else{
        total_fare = baseFare() + (baseFare()*10)/100;
    }
    return total_fare;
}

std::ostream &operator<<(std::ostream &os, const OnlinePayment &rhs) {
    os << static_cast<const CabBooking&>(rhs)<<std::endl;
    os<<"Payment type "<<static_cast<int>(rhs._payment)<<std::endl;
    os << " _drop_counts: " << rhs._drop_counts<<std::endl;
    return os;
}

OnlinePayment::OnlinePayment(std::string booking_id, std::string pickup_location, std::string drop_location, float base_fare, PaymentType payment, unsigned int drop_counts)
            : CabBooking(booking_id, pickup_location, drop_location, base_fare), _payment{payment}, _drop_counts{drop_counts} {}


