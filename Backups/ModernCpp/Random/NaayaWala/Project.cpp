#include "Project.h"
std::ostream &operator<<(std::ostream &os, const Project &rhs) {
    os << "_name: " << rhs._name;
    return os;
}

Project::Project(std::string name): _name {name} {}