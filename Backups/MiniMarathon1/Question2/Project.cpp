#include "Project.h"
std::ostream &operator<<(std::ostream &os, const Project &rhs) {
    os << "_project_name: " << rhs._project_name
       << " _project_budget: " << rhs._project_budget;
    return os;
}

Project::Project(std::string project_name, float project_price)
        : _project_name{project_name}, _project_budget{project_price} {}