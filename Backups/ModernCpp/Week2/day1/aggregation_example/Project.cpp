#include "Project.h"

Project::Project(std::string project_id, float project_budget, unsigned int team_size)
        : _project_id{project_id}, _project_budget{project_budget}, _team_size{team_size} {}
        
std::ostream &operator<<(std::ostream &os, const Project &rhs) {
    os << "_project_id: " << rhs._project_id
        << " _project_budget: " << rhs._project_budget
        << " _team_size: " << rhs._team_size;
    return os;
}
