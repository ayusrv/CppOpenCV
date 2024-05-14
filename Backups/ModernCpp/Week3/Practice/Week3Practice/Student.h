#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "GenderType.h"

class Student
{
private:
    std::string _name;
    Gender _gender;
    int _age;
    int _roll_no;
    std::string _class_teacher;
public:
    Student()=default;
    Student(const Student &)=delete;
    Student(Student && )=delete;
    Student & operator=(const Student & )=delete;
    Student &operator=(Student &&)=delete;
    ~Student()=default;
    Student(std::string name, Gender gender, int age, int roll_no, std::string class_tacher);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    Gender gender() const { return _gender; }
    void setGender(const Gender &gender) { _gender = gender; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }

    int rollNo() const { return _roll_no; }
    void setRollNo(int roll_no) { _roll_no = roll_no; }

    std::string classTeacher() const { return _class_teacher; }
    void setClassTeacher(const std::string &class_teacher) { _class_teacher = class_teacher; }

    friend std::ostream &operator<<(std::ostream &os, const Student &rhs);
};

#endif // STUDENT_H
