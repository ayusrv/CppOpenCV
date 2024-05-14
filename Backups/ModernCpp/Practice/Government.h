#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Employee.h"
#include <ostream>

class Government : public Employee
{
private:
    int _id;
public:
    Government() = default;
    Government(const Government&) = default;
    Government(Government&&) = default;
    Government& operator=(Government&&) = default;
    Government& operator=(const Government&) = default;
    ~Government() = default;
    Government(std::string name, std::string address, int age, Gender gender, float salary, EmployeeType emp_type, int id);

    float CalculateTax();

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    friend std::ostream &operator<<(std::ostream &os, const Government &rhs);
};

#endif // GOVERNMENT_H
