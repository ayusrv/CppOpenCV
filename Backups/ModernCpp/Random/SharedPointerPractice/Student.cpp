#include "Student.h"

std::ostream &operator<<(std::ostream &os, const Student &rhs)
{
    os << "_name: " << rhs._name
       << " _address: " << rhs._address;
       for(float f : rhs.marks()){
        os << "Marks: "<<f;
       }
    return os;
}

Student::Student(std::string name, std::string address, std::array<float,4> marks)
        : _name{name}, _address{address} , _marks{marks}{}