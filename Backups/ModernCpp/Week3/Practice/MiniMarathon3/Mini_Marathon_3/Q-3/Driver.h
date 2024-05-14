#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include "DriverRating.h"

class Driver
{
private:
    std::string _driverId{""};
    DriverRating _drate{DriverRating::STAR_1};
public:
    Driver()=default;          // Default constructor enabled 
    
    Driver(const Driver&)=delete;              // Copy constructor disabled
    
    Driver(Driver&&)=delete;                   // Move Constructor disabled
    
    Driver& operator=(const Driver&)=delete;      // Copy Assignment Operator diabled
    
    Driver& operator=(Driver&&)=delete;       // Move Assignment Operator disabled
    
    ~Driver()=default;                      // Default destructor enabled

    Driver(std::string driverId, DriverRating drate);

    std::string driverId() const { return _driverId; }
    void setDriverId(const std::string &driverId) { _driverId = driverId; }

    DriverRating drate() const { return _drate; }
    void setDrate(const DriverRating &drate) { _drate = drate; }

    friend std::ostream &operator<<(std::ostream &os, const Driver &rhs);
};

#endif // DRIVER_H
