#ifndef PERMIT_H
#define PERMIT_H

#include <iostream>
#include "PermitType.h"

class Permit
{
private:
    std::string _serial_numer;
    PermitType _permit_type;
    int _permit_duration_left;
public:
    Permit() = delete;
    Permit(const Permit&) = delete;
    Permit(Permit&&) = delete;
    Permit& operator = (const Permit&) = delete;
    Permit& operator = (Permit&&) = delete;

    Permit(std::string serial_number, PermitType permit_type, int permit_duration_left);


    std::string serialNumer() const { return _serial_numer; }
    void setSerialNumer(int serial_numer) { _serial_numer = serial_numer; }

    int permitDurationLeft() const { return _permit_duration_left; }
    void setPermitDurationLeft(int permit_duration_left) { _permit_duration_left = permit_duration_left; }

    PermitType permitType() const { return _permit_type; }
    void setPermitType(const PermitType &permit_type) { _permit_type = permit_type; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
    
};

#endif // PERMIT_H