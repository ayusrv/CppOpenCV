#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
#include <memory>
#include "Student.h"

class Branch
{
private:
    std::string _branch;
    std::string _date;
    std::shared_ptr<Student> _student; //Student* _student
public:
    Branch() = delete;
    Branch(const Branch&) = delete;
    Branch& operator = (Branch&) = delete;
    Branch& operator = (Branch&& std) = delete;
    Branch(Branch&&) = delete;
    ~Branch() {}

    Branch(std::string branch, std::string date, std::shared_ptr<Student> student);

    std::string branch() const { return _branch; }
    void setBranch(const std::string &branch) { _branch = branch; }

    std::string date() const { return _date; }
    void setDate(const std::string &date) { _date = date; }

    std::shared_ptr<Student> student() const { return _student; }
    void setStudent(const std::shared_ptr<Student> &student) { _student = student; }

    friend std::ostream &operator<<(std::ostream &os, const Branch &rhs);
};

#endif // BRANCH_H