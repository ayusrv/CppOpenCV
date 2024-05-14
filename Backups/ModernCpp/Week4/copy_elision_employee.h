#ifndef COPY_ELISION_CEmployee_H
#define COPY_ELISION_CEmployee_H

#include <iostream>

class CEmployee
{
private:
    std::string _name {""};
    float _salary {0.0f};
    std::string _designation {""};
    int _exp_years {-1};
public:
    CEmployee(std::string name, float salary, std::string designation, int exp_years) 
                : _name{name}, _salary{salary}, _designation{designation}, _exp_years{exp_years} {}
    CEmployee()=default;
    CEmployee(const CEmployee &)=default;
    CEmployee(CEmployee && )=delete;
    CEmployee & operator=(const CEmployee & )=delete;
    CEmployee &operator=(CEmployee &&)=default;
    ~CEmployee()=default;

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    std::string designation() const { return _designation; }
    void setDesignation(const std::string &designation) { _designation = designation; }

    int expYears() const { return _exp_years; }
    void setExpYears(int exp_years) { _exp_years = exp_years; }

    friend std::ostream &operator<<(std::ostream &os, const CEmployee &rhs);
};
inline std::ostream &operator<<(std::ostream &os, const CEmployee &rhs) {
    os << "_name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _designation: " << rhs._designation
       << " _exp_years: " << rhs._exp_years;
    return os;
}
#endif // COPY_ELISION_CEmployee_H
