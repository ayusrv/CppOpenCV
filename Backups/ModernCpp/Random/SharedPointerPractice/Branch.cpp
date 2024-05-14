#include "Branch.h"
std::ostream &operator<<(std::ostream &os, const Branch &rhs) {
    os << "_branch: " << rhs._branch
       << " _date: " << rhs._date
       << " _student: " << *rhs._student;
    return os;
}

Branch::Branch(std::string branch, std::string date, std::shared_ptr<Student> student)
        : _branch{branch}, _date{date}, _student{student} {}