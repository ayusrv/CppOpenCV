#include "Teacher.h"
std::ostream &operator<<(std::ostream &os, const Teacher &rhs) {
    os << "_emp_id: " << rhs._emp_id
       << " _name: " << rhs._name
       << " _gender: ";
    os<<" Details of students is: \n";
    for(VType v : rhs._variant)
    {
        std::visit([&](auto&& args)
        {
            os<<*args;
        },v);
    }
       if(rhs._gender == Gender::MALE) os<<" Male";
       else if(rhs._gender==Gender::FEMALE) os<<" Female";
       else os<<" LGTV/ LGTV+";
    return os;
}

Teacher::Teacher(std::string emp_id, std::string name, VConatiner variant, Gender gender)
        : _emp_id{emp_id}, _name{name}, _variant{variant}, _gender{gender} {}