#ifndef COLLEGE_H
#define COLLEGE_H

#include<iostream>
#include "Person.h"
class College : public Person
{
private:
    std::string _college_name {""};
    std::string _branch {""};
    int _year {0};
    std::string _uid {""};
public:
    College() = delete;
    College(const College&) = delete;
    College(College &&) = delete;
    College& operator= (const College&) = delete;
    College& operator= (College&&)= delete; 

    College(std::string college_name, std::string branch, int year, std::string uid);

    std::string collegeName() const { return _college_name; }

    std::string branch() const { return _branch; }
    void setBranch(const std::string &branch) { _branch = branch; }

    int year() const { return _year; }
    void setYear(int year) { _year = year; }

    std::string uid() const { return _uid; }

    friend std::ostream &operator<<(std::ostream &os, const College &rhs);
    
};

#endif // COLLEGE_H
