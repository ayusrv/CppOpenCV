#ifndef SCHOOL_H
#define SCHOOL_H

#include<iostream>
#include "Person.h"

class School : public Person
{
private:
    std::string _school_name {""};
    int _roll {0};
    float _tenth_marks {0};
    float _twelth_marks {0};
public:
    School() = delete;
    School(const School&) = delete;
    School(School&&) = delete;
    School& operator = (const School&) = delete;
    School& operator = (School &&) = delete;

    School(std::string school_name, int roll, float tenth_marks, float twelth_marks);

    std::string schoolName() const { return _school_name; }
    void setSchoolName(const std::string &school_name) { _school_name = school_name; }

    int roll() const { return _roll; }
    void setRoll(int roll) { _roll = roll; }

    float tenthMarks() const { return _tenth_marks; }

    float twelthMarks() const { return _twelth_marks; }

    friend std::ostream &operator<<(std::ostream &os, const School &rhs);
    
};

#endif // SCHOOL_H
