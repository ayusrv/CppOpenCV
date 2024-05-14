#include "OfflineStudent.h"

OfflineStudent::OfflineStudent(std::string name, int roll, Gender gender, std::vector<int> marks)
                : _name{name}, _roll{roll}, _gender{gender}, _marks{marks} {}
std::ostream &operator<<(std::ostream &os, const OfflineStudent &rhs) {
    os << "_name: " << rhs._name
       << " _roll: " << rhs._roll
       << " _gender: ";
       if(rhs._gender == Gender::MALE) os<<" Male";
       else if(rhs._gender == Gender::FEMALE) os<<" Female";
       else os<<" LGTV/ LGTV+";
    os << " _marks: ";
    for(int i : rhs._marks) os<<" "<<i;
    os<<std::endl;
    return os;
}
