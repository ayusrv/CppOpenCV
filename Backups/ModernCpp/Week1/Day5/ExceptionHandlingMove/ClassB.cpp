#include "ClassB.h"

ClassB::~ClassB()
{
    // delete _aClass;
}
ClassB::ClassB(int phNo, ClassA *aClass): _phNo(phNo), _aClass(aClass) {}
std::ostream &operator<<(std::ostream &os, const ClassB &rhs)
{
    os << "_phNo: " << rhs._phNo
       << " _aClass: " << rhs._aClass;
    return os;
}
