#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>

class Project
{
private:
    std::string _name;
public:
    Project()=default;
    Project(const Project &)=default;
    Project(Project && )=default;
    Project & operator=(const Project & )=delete;
    Project &operator=(Project &&)=delete;
    ~Project()=default;
    Project(std::string name);

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);
};

#endif // PROJECT_H
