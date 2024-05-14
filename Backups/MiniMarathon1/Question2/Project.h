#ifndef PROJECT_H
#define PROJECT_H


#include <iostream>
class Project
{
private:
    std::string _project_name;
    float _project_budget;
public:
    Project() = delete; //Deleting the default constructor
    ~Project() = default; //Defult of Destructor
    Project(const Project&) = delete; //Deleting the Copy COnstructor
    Project(Project&&) = delete; //Deleteing the move symantic
    Project& operator = (Project&) = delete; //Deleting the = operator
    Project& operator = (Project&&) = delete; //Deleting the = operator
    Project(std::string project_name, float project_price);

    float projectBudget() const { return _project_budget; }
    void setProjectBudget(float project_budget) { _project_budget = project_budget; }

    std::string projectName() const { return _project_name; }
    void setProjectName(const std::string &project_name) { _project_name = project_name; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);
};

#endif // PROJECT_H
