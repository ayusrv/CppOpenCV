#ifndef CABRIDE_H
#define CABRIDE_H

#include "RideType.h"
#include "PaymentMode.h"
#include "Driver.h"
#include <variant>
#include <memory>


using DriverPointer = std::shared_ptr<Driver>;
using DriverRef = std::reference_wrapper<DriverPointer>; 

class CabRide
{
private:
    std::variant<int, std::string> _id;
    RideType _rType;
    PaymentMode _pMode;
    float _fare{0.0f};
    std::string _dropLocation;
    std::string _pickupLocation;
    DriverRef _cabDriver;

public:
    CabRide()=default;          // Default constructor enabled 
    
    CabRide(const CabRide&)=delete;              // Copy constructor disabled
    
    CabRide(CabRide&&)=delete;                   // Move Constructor disabled
    
    CabRide& operator=(const CabRide&)=delete;      // Copy Assignment Operator diabled
    
    CabRide& operator=(CabRide&&)=delete;       // Move Assignment Operator disabled
    
    ~CabRide()=default;                      // Default destructor enabled

    CabRide(std::variant<int, std::string> id, RideType rType, PaymentMode pMode, float fare, std::string dropLocation, std::string pickupLocation, DriverRef cabDriver);

    std::variant<int, std::string> id() const { return _id; }
    void setId(const std::variant<int, std::string> &id) { _id = id; }

    RideType rType() const { return _rType; }
    void setRType(const RideType &rType) { _rType = rType; }

    PaymentMode pMode() const { return _pMode; }
    void setPMode(const PaymentMode &pMode) { _pMode = pMode; }

    float fare() const { return _fare; }
    void setFare(float fare) { _fare = fare; }

    std::string dropLocation() const { return _dropLocation; }
    void setDropLocation(const std::string &dropLocation) { _dropLocation = dropLocation; }

    std::string pickupLocation() const { return _pickupLocation; }
    void setPickupLocation(const std::string &pickupLocation) { _pickupLocation = pickupLocation; }

    DriverRef cabDriver() const { return _cabDriver; }
    void setCabDriver(const DriverRef &cabDriver) { _cabDriver = cabDriver; }
};

#endif // CABRIDE_H
