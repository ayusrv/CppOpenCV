#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include "GenderType.h"

class Teacher
{
private:
    std::string _name;
    Gender _gender;
    int _age;
    int _emp_id;
    float _salary;
public:
    Teacher()=default;
    Teacher(const Teacher &)=delete;
    Teacher(Teacher && )=delete;
    Teacher & operator=(const Teacher & )=delete;
    Teacher &operator=(Teacher &&)=delete;
    ~Teacher()=default;
    Teacher(std::string name, Gender gender, int age, int emp_id, float salary);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    Gender gender() const { return _gender; }
    void setGender(const Gender &gender) { _gender = gender; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }

    int empId() const { return _emp_id; }
    void setEmpId(int emp_id) { _emp_id = emp_id; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    friend std::ostream &operator<<(std::ostream &os, const Teacher &rhs);
};

#endif // TEACHER_H
