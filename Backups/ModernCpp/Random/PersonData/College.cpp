#include "College.h"
std::ostream &operator<<(std::ostream &os, const College &rhs) {
    os << "_college_name: " << rhs._college_name
       << " _branch: " << rhs._branch
       << " _year: " << rhs._year
       << " _uid: " << rhs._uid;
    return os;
}

College::College(std::string college_name, std::string branch, int year, std::string uid)
{
}