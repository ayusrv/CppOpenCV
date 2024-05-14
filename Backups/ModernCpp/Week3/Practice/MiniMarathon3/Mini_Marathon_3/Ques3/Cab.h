#ifndef CAB_H
#define CAB_H

#include <variant>
#include <memory>
#include <iostream>
#include "Driver.h"
#include "RideType.h"
#include "PaymentMode.h"

using DriverPointer = std::shared_ptr<Driver>;
using DriverReference = std::reference_wrapper<DriverPointer>;
using VType = std::variant<int, std::string>;

class Cab{
    VType _id;
    RideType _ride_type;
    PaymentMode _payment_mode;
    float _fare;
    std::string _pickup_location;
    std::string _drop_location;
    DriverReference _cab_driver;

public:

    Cab()=default;
    Cab(const Cab &)=delete;
    Cab(Cab && )=delete;
    Cab & operator=(const Cab & )=delete;
    Cab &operator=(Cab &&)=delete;
    ~Cab()=default;
    Cab(VType id, RideType ride_type, PaymentMode payment_mode, float fare, std::string pickup_location, std::string drop_location, DriverReference cab_driver);

    VType id() const { return _id; }
    void setId(const VType &id) { _id = id; }

    RideType rideType() const { return _ride_type; }
    void setRideType(const RideType &ride_type) { _ride_type = ride_type; }

    PaymentMode paymentMode() const { return _payment_mode; }
    void setPaymentMode(const PaymentMode &payment_mode) { _payment_mode = payment_mode; }

    float fare() const { return _fare; }
    void setFare(float fare) { _fare = fare; }

    std::string pickupLocation() const { return _pickup_location; }
    void setPickupLocation(const std::string &pickup_location) { _pickup_location = pickup_location; }

    std::string dropLocation() const { return _drop_location; }
    void setDropLocation(const std::string &drop_location) { _drop_location = drop_location; }

    DriverReference cabDriver() const { return _cab_driver; }
    void setCabDriver(const DriverReference &cab_driver) { _cab_driver = cab_driver; }

    friend std::ostream &operator<<(std::ostream &os, const Cab &rhs);
};

#endif // CAB_H
