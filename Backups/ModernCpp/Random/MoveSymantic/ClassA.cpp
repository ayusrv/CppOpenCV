#include "ClassA.h"
std::ostream &operator<<(std::ostream &os, const ClassA &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name;
    return os;
}

ClassA::ClassA(int id, std::string name,const char *msg)
        : _id{id}, _name{name} {
            _msg=new char[strlen(msg)+1];
            strcpy(_msg,msg);
        }