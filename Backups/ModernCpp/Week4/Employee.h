#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    std::string _name {""};
    float _salary {0.0f};
    std::string _designation {""};
    int _exp_years {-1};
public:
    Employee(std::string name, float salary, std::string designation, int exp_years) 
                : _name{name}, _salary{salary}, _designation{designation}, _exp_years{exp_years} {}
    Employee()=default;
    Employee(const Employee &)=default;
    Employee(Employee && )=default;
    Employee & operator=(const Employee & )=default;
    Employee &operator=(Employee &&)=default;
    ~Employee()=default;

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    std::string designation() const { return _designation; }
    void setDesignation(const std::string &designation) { _designation = designation; }

    int expYears() const { return _exp_years; }
    void setExpYears(int exp_years) { _exp_years = exp_years; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};
inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _designation: " << rhs._designation
       << " _exp_years: " << rhs._exp_years;
    return os;
}

#endif // EMPLOYEE_H
