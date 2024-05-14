#ifndef ONLINEPAYMENT_H
#define ONLINEPAYMENT_H

#include "PaymentType.h"
#include "CabBooking.h"
#include <iostream>
class OnlinePayment : public CabBooking
{
private:
    PaymentType _payment;
    unsigned int _drop_counts;
public:
    OnlinePayment() = delete;
    OnlinePayment(const OnlinePayment&) = delete;
    OnlinePayment(OnlinePayment&&) = delete;
    OnlinePayment& operator = (const OnlinePayment&) = delete;
    OnlinePayment& operator = (OnlinePayment&&) = delete;
    ~OnlinePayment() = default;
    OnlinePayment(std::string booking_id, std::string pickup_location, std::string drop_location, float base_fare, PaymentType payment, unsigned int drop_counts);

    PaymentType payment() const { return _payment; }
    void setPayment(const PaymentType &payment) { _payment = payment; }

    unsigned int dropCounts() const { return _drop_counts; }
    void setDropCounts(unsigned int drop_counts) { _drop_counts = drop_counts; }

    std::string PaymentTypeConverter(PaymentType payment);
    friend std::ostream &operator<<(std::ostream &os, const OnlinePayment &rhs);

    float CabFareCalculation() override ;

};

#endif // ONLINEPAYMENT_H
