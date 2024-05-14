#include "Permit.h"
std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_serial_numer: " << rhs._serial_numer
       << " _permit_type: ";
        if(rhs._permit_type == PermitType::LEASE)
            os<<"Lease";
        else
            os<<"Owned";
       os<< " _permit_duration_left: " << rhs._permit_duration_left;
    return os;
}

Permit::Permit(std::string serial_number, PermitType permit_type, int permit_duration_left)
        : _serial_numer{serial_number}, _permit_type{permit_type}, _permit_duration_left{permit_duration_left} {}

