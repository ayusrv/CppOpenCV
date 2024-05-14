#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

#include "TransmissionType.h"
#include "VehicleCategory.h"

class Vehicle
{
private:
    std::string _m_vehicle_id;
    float _m_vehicle_price;
    VehicleCategory _m_vehicle_category;
    TransmissionType _m_transmission_type;
    int _m_boot_space;
    bool _m_vehicle_insured;

public:
    Vehicle() = default;
    Vehicle(const Vehicle&) = default;
    Vehicle(Vehicle&&) = default;
    Vehicle& operator= (const Vehicle&) = default;
    Vehicle& operator= (Vehicle&&) = default;
    Vehicle(std::string m_vehicle_id, float m_vehicle_price, VehicleCategory m_vehicle_category, TransmissionType m_transmission_type, int m_boot_space, bool m_vehicle_insured);
    ~Vehicle() = default;

    std::string mVehicleId() const { return _m_vehicle_id; }
    void setMVehicleId(const std::string &m_vehicle_id) { _m_vehicle_id = m_vehicle_id; }

    float mVehiclePrice() const { return _m_vehicle_price; }
    void setMVehiclePrice(float m_vehicle_price) { _m_vehicle_price = m_vehicle_price; }

    VehicleCategory mVehicleCategory() const { return _m_vehicle_category; }
    void setMVehicleCategory(const VehicleCategory &m_vehicle_category) { _m_vehicle_category = m_vehicle_category; }

    TransmissionType mTransmissionType() const { return _m_transmission_type; }
    void setMTransmissionType(const TransmissionType &m_transmission_type) { _m_transmission_type = m_transmission_type; }

    int mBootSpace() const { return _m_boot_space; }
    void setMBootSpace(int m_boot_space) { _m_boot_space = m_boot_space; }

    bool mVehicleInsured() const { return _m_vehicle_insured; }
    void setMVehicleInsured(bool m_vehicle_insured) { _m_vehicle_insured = m_vehicle_insured; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
