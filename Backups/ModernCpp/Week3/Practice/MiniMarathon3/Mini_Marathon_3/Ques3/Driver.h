#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include "DriverRating.h"

class Driver{
    std::string _driver_id;
    DriverRating _driver_rating;

public:

    Driver()=default;
    Driver(const Driver &)=delete;
    Driver(Driver && )=delete;
    Driver & operator=(const Driver & )=delete;
    Driver &operator=(Driver &&)=delete;
    ~Driver()=default;
    Driver(std::string driver_id, DriverRating driver_rating);

    DriverRating driverRating() const { return _driver_rating; }
    void setDriverRating(const DriverRating &driver_rating) { _driver_rating = driver_rating; }

    std::string driverId() const { return _driver_id; }
    void setDriverId(const std::string &driver_id) { _driver_id = driver_id; }

    friend std::ostream &operator<<(std::ostream &os, const Driver &rhs);
};

#endif // DRIVER_H
