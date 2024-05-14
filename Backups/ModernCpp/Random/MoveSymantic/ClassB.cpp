#include "ClassB.h"
std::ostream &operator<<(std::ostream &os, const ClassB &rhs) {
    os << "ptr: " << rhs.ptr;
    return os;
}

ClassB::ClassB(std::shared_ptr<ClassA> ptr1)
        : ptr{ptr1} {}