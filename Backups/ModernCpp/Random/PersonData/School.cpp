#include "School.h"
std::ostream &operator<<(std::ostream &os, const School &rhs) {
    os << static_cast<const Person &>(rhs)
       << " _school_name: " << rhs._school_name
       << " _roll: " << rhs._roll
       << " _tenth_marks: " << rhs._tenth_marks
       << " _twelth_marks: " << rhs._twelth_marks;
    return os;
}

School::School(std::string school_name, int roll, float tenth_marks, float twelth_marks)
        :_school_name(school_name), _roll(roll), _tenth_marks(tenth_marks), _twelth_marks(twelth_marks) {}