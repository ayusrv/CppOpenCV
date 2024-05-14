#ifndef TEACHER_H
#define TEACHER_H

#include "OfflineStudent.h"
#include "OnlineStudent.h"
#include <variant>
#include <memory>
#include <vector>
#include <ostream>

using OfflineStudentPointer = std::shared_ptr<OfflineStudent>;
using OnlineStudentPointer = std::shared_ptr<OnlineStudent>;
using VType = std::variant<OfflineStudentPointer, OnlineStudentPointer>;
using VConatiner = std::vector<VType>;

class Teacher
{
private:

    std::string _emp_id;
    std::string _name;
    VConatiner _variant;
    Gender _gender;

public:

    Teacher() = default;
    Teacher(const Teacher&) = delete;
    Teacher(Teacher&&) = delete;
    Teacher& operator = (const Teacher&) = delete;
    Teacher& operator = (Teacher&&) = delete;
    ~Teacher() = default;
    Teacher(std::string emp_id, std::string name, VConatiner variant, Gender gender);

    std::string empId() const { return _emp_id; }
    void setEmpId(const std::string &emp_id) { _emp_id = emp_id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    VConatiner variant() const { return _variant; }
    void setVariant(const VConatiner &variant) { _variant = variant; }

    Gender gender() const { return _gender; }
    void setGender(const Gender &gender) { _gender = gender; }

    friend std::ostream &operator<<(std::ostream &os, const Teacher &rhs);
};

#endif // TEACHER_H
