#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <array>

class Student
{
private:
    std::string _name;
    std::string _address;
    std::array<float,4> _marks;
public:
    Student(std::string name, std::string address, std::array<float,4> marks);
    Student() = default;
    Student(const Student&) = delete;
    Student& operator = (Student&) = delete;
    Student& operator = (Student&& st) = delete;
    Student(Student&& st) : _name(std::move(st._name)), _address(std::move(st._address)), _marks(std::move(st._marks)) {}
    ~Student() {}

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    std::string address() const { return _address; }
    void setAddress(const std::string &address) { _address = address; }

    std::array<float,4> marks() const { return _marks; }
    void setMarks(const std::array<float,4> &marks) { _marks = marks; }

    friend std::ostream &operator<<(std::ostream &os, const Student &rhs);

};

#endif // STUDENT_H