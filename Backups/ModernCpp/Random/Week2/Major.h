#ifndef CLASSB_H
#define CLASSB_H

#include "classA.h"
#include <functional>
#include<iostream>
#include <ostream>
class Major
{
private:
    int _id;
    std::string _name;
    std::reference_wrapper<classA> _classA;
public:
    Major() =delete;
    ~Major() {}
    Major(int id, std::string name, std::reference_wrapper<classA> classa):
    _id{id},_name{name},_classA{classa}
    {

    }
    

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    std::reference_wrapper<classA> classa() const { return _classA; }

    friend std::ostream &operator<<(std::ostream &os, const Major &rhs) {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name
           << " _classA: " << rhs._classA;
        return os;
    }

};

#endif // CLASSB_H
