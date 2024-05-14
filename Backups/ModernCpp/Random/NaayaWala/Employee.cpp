#include "Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _projects: " << rhs._projects;
    return os;
}

Employee::Employee(int id, std::reference_wrapper<Project> projects)
        : _id{id}, _projects{projects} {}