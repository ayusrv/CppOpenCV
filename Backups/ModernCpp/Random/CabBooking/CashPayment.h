#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include <iostream>
#include "CabBooking.h"


class CashPayment : public CabBooking
{
private:
    unsigned int _reward_points;
public:
    CashPayment() = delete;
    CashPayment(const CashPayment&) = delete;
    CashPayment(CashPayment&&) = delete;
    CashPayment& operator = (const CashPayment&) = delete;
    CashPayment& operator = (CashPayment&&) = delete;
    ~CashPayment() = default;
    CashPayment(std::string booking_id, std::string pickup_location, std::string drop_location, float base_fare, unsigned int reward_points);

    float CabFareCalculation() override;

    unsigned int rewardPoints() const { return _reward_points; }
    void setRewardPoints(unsigned int reward_points) { _reward_points = reward_points; }

    friend std::ostream &operator<<(std::ostream &os, const CashPayment &rhs);

    
};

#endif // CASHPAYMENT_H
