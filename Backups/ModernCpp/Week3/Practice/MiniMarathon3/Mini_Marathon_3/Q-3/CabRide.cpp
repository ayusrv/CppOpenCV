#include "CabRide.h"

CabRide::CabRide(std::variant<int, std::string> id, RideType rType, PaymentMode pMode, float fare, std::string dropLocation, std::string pickupLocation, DriverRef cabDriver)
:_id{id}, _rType{rType}, _pMode{pMode}, _fare{fare}, _dropLocation{dropLocation}, _pickupLocation{pickupLocation}, _cabDriver{cabDriver}
{}