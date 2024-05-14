#ifndef ONLINESTUDENT_H
#define ONLINESTUDENT_H

#include <iostream>
#include <vector>
#include "Gender.h"

class OnlineStudent
{
private:
    std::string _name;
    int _roll;
    Gender _gender;
    std::vector<int> _marks;
public:
    OnlineStudent() = default;
    OnlineStudent(const OnlineStudent&) = default;
    OnlineStudent(OnlineStudent&&) = delete;
    OnlineStudent & operator = (const OnlineStudent&) = default;
    OnlineStudent& operator = (OnlineStudent&&) = delete;
    ~OnlineStudent() = default;
    OnlineStudent(std::string name, int roll, Gender gender, std::vector<int> marks);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int roll() const { return _roll; }
    void setRoll(int roll) { _roll = roll; }

    Gender gender() const { return _gender; }
    void setGender(const Gender &gender) { _gender = gender; }

    std::vector<int> marks() const { return _marks; }
    void setMarks(const std::vector<int> &marks) { _marks = marks; }

    friend std::ostream &operator<<(std::ostream &os, const OnlineStudent &rhs);
};

#endif // ONLINESTUDENT_H
