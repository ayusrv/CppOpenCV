#include "Vehicle.h"
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_m_vehicle_id: " << rhs._m_vehicle_id
       << " _m_vehicle_price: " << rhs._m_vehicle_price
       << " _m_vehicle_category: ";
       if(rhs._m_vehicle_category == VehicleCategory::GOVT) os<<" GOVT ";
       else if(rhs._m_vehicle_category == VehicleCategory::PRIVATE) os<<" Private ";
       else os<<" Public ";
    os << " _m_transmission_type: ";
    if( rhs._m_transmission_type== TransmissionType::AMT) os<< " AMT ";
    else if( rhs._m_transmission_type == TransmissionType::AUTOMATIC) os<<" Automatic ";
    else os<<" Manual ";
    os << " _m_boot_space: " << rhs._m_boot_space
       << " _m_vehicle_insured: " << rhs._m_vehicle_insured;
    return os;
}

Vehicle::Vehicle(std::string m_vehicle_id, float m_vehicle_price, VehicleCategory m_vehicle_category, TransmissionType m_transmission_type, int m_boot_space, bool m_vehicle_insured)
        : _m_vehicle_id{m_vehicle_id}, _m_vehicle_price{m_vehicle_price}, _m_vehicle_category{m_vehicle_category}, _m_transmission_type{m_transmission_type}, _m_boot_space{m_boot_space}, _m_vehicle_insured{m_vehicle_insured} {}