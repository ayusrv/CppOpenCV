#ifndef OFFLINESTUDENT_H
#define OFFLINESTUDENT_H

#include <iostream>
#include <vector>
#include "Gender.h"

class OfflineStudent
{
private:
    std::string _name;
    int _roll;
    Gender _gender;
    std::vector<int> _marks;
public:
    OfflineStudent() = default;
    OfflineStudent(const OfflineStudent&) = default;
    OfflineStudent(OfflineStudent&&) = delete;
    OfflineStudent & operator = (const OfflineStudent&) = default;
    OfflineStudent& operator = (OfflineStudent&&) = delete;
    ~OfflineStudent() = default;
    OfflineStudent(std::string name, int roll, Gender gender, std::vector<int> marks);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int roll() const { return _roll; }
    void setRoll(int roll) { _roll = roll; }

    Gender gender() const { return _gender; }
    void setGender(const Gender &gender) { _gender = gender; }

    std::vector<int> marks() const { return _marks; }
    void setMarks(const std::vector<int> &marks) { _marks = marks; }

    friend std::ostream &operator<<(std::ostream &os, const OfflineStudent &rhs);
};

#endif // OfflineStudent_H
