#include "Driver.h"

std::ostream &operator<<(std::ostream &os, const Driver &rhs) {
    os << "Driver Id: " << rhs._driverId;
    return os;
}

Driver::Driver(std::string driverId, DriverRating drate)
:_driverId{driverId}, _drate{drate}{}
