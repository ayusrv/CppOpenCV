#ifndef SECTION_H
#define SECTION_H

#include "Branch.h"
#include <iostream>

class Section
{
private:
    std::string _uid;
    std::string _section_name;
    std::shared_ptr<Branch> _branch;  //Branch* _branch
public:
    Section() = delete;
    Section(const Section&) = delete;
    Section& operator = (Section&) = delete;
    Section& operator = (Section&& std) = delete;
    Section(Section&&) = delete;
    ~Section() {}

    Section(std::string uid, std::string section_name, std::shared_ptr<Branch> branch);

    std::shared_ptr<Branch> branch() const { return _branch; }
    void setBranch(const std::shared_ptr<Branch> &branch) { _branch = branch; }

    std::string sectionName() const { return _section_name; }
    void setSectionName(const std::string &section_name) { _section_name = section_name; }

    std::string uid() const { return _uid; }
    void setUid(const std::string &uid) { _uid = uid; }

    friend std::ostream &operator<<(std::ostream &os, const Section &rhs);
};

#endif // SECTION_H
