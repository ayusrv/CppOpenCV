#ifndef SCHOOL_H
#define SCHOOL_H

#include "Student.h"
#include "Teacher.h"
#include <variant>
#include <memory>
#include <ostream>

using StudentPointer = std::shared_ptr<Student>;
using TeacherPointer = std::shared_ptr<Teacher>;
using VType = std::variant<StudentPointer, TeacherPointer>;

class School
{
private:
    VType _variant;
    std::string _school_name;
public:
    School()=default;
    School(const School &)=delete;
    School(School && )=delete;
    School & operator=(const School & )=delete;
    School &operator=(School &&)=delete;
    ~School()=default;
    School(VType variant, std::string school_name);

    VType variant() const { return _variant; }
    void setVariant(const VType &variant) { _variant = variant; }

    std::string schoolName() const { return _school_name; }
    void setSchoolName(const std::string &school_name) { _school_name = school_name; }

    friend std::ostream &operator<<(std::ostream &os, const School &rhs);
};

#endif // SCHOOL_H
