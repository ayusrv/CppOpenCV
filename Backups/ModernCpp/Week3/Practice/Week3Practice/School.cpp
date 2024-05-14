#include "School.h"
std::ostream &operator<<(std::ostream &os, const School &rhs) {
    os << "_variant: ";
    std::visit([&](auto&& args){
        std::cout<<*args<<std::endl;
    }, rhs._variant);
    os   << " _school_name: " << rhs._school_name;
    return os;
}

School::School(VType variant, std::string school_name)
        : _variant(std::ref(variant)), _school_name{school_name} {}