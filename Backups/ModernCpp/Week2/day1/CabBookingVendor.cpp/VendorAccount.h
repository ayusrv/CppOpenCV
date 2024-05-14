#ifndef VENDOR_H
#define VENDOR_H

#include "Account.h"
#include "Driver.h"
#include "CabUnit.h"
#include <iostream>
#include <vector>

using DriverContainer = std::vector<Driver*>;
using CabUnitContainer = std::vector<CabUnit*>;

class VendorAccount : public Account
{
private:
    std::string _vendorName;
    DriverContainer _driver {};
    CabUnitContainer _cabUnit {};

public:
    VendorAccount() = delete;
    VendorAccount(const VendorAccount&) = delete;
    VendorAccount(const VendorAccount &&) = delete;
    VendorAccount& operator = (const VendorAccount&&) = delete;
    VendorAccount& operator = (const VendorAccount&) = delete;
    ~VendorAccount() = default;

    VendorAccount(std::string name, std::string vendorName);
    VendorAccount(std::string name, std::string vendorName,const DriverContainer &drivers);
    VendorAccount(std::string name, std::string vendorName,const DriverContainer &drivers, const CabUnitContainer &cabUnit);

    void RegisterAccount() override;

    friend std::ostream &operator<<(std::ostream &os, const VendorAccount &rhs);
};

#endif // VENDOR_H
