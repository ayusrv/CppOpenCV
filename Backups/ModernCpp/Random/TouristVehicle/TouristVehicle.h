#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include "Permit.h"
#include <memory>
#include <ostream>
#include "VehicleType.h"

class TouristVehicle
{
private:
    std::string _number;
    VehicleType _vehicle_type;
    int _seat_count;
    float _per_hour_booking_charge;
    std::reference_wrapper<Permit> _permit;
public:
    TouristVehicle() = delete;
    TouristVehicle(const TouristVehicle&) = delete;
    TouristVehicle(TouristVehicle&&) = delete;
    TouristVehicle& operator = (const TouristVehicle&) = delete;
    TouristVehicle& operator = (TouristVehicle&&) = delete;
    TouristVehicle(std::string number, VehicleType vehicle_type, int seat_count, float per_hour_booking_charge, std::reference_wrapper<Permit> permit);

    std::string number() const { return _number; }
    void setNumber(const std::string &number) { _number = number; }

    VehicleType vehicleType() const { return _vehicle_type; }
    void setVehicleType(const VehicleType &vehicle_type) { _vehicle_type = vehicle_type; }

    int sertCount() const { return _seat_count; }
    void setSertCount(int seat_count) { _seat_count = seat_count; }

    float perHourBookingCharge() const { return _per_hour_booking_charge; }
    void setPerHourBookingCharge(float per_hour_booking_charge) { _per_hour_booking_charge = per_hour_booking_charge; }


    std::reference_wrapper<Permit> permit() const { return _permit; }
    void setPermit(const std::reference_wrapper<Permit> &permit) { _permit = permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TOURISTVEHICLE_H
