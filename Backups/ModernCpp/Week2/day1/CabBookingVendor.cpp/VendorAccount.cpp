#include "VendorAccount.h"

VendorAccount::VendorAccount(std::string name, std::string vendorName)
        : Account(name), _vendorName{vendorName} {}

VendorAccount::VendorAccount(std::string name, std::string vendorName,const DriverContainer &drivers)
        : VendorAccount(name, vendorName){
            _driver = drivers;
        }

VendorAccount::VendorAccount(std::string name, std::string vendorName,const DriverContainer &drivers, const CabUnitContainer &cabUnit)
        : VendorAccount(name, vendorName, drivers){
            _cabUnit = cabUnit; 
        }

void VendorAccount::RegisterAccount()
{
    std::cout<<"VendorAccount Registered/verified Successfully"<<std::endl;
}
std::ostream &operator<<(std::ostream &os, const VendorAccount &rhs) {
    os << static_cast<const Account &>(rhs)
       << " _vendorName: " << rhs._vendorName;
    return os;
}
