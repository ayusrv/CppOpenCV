#ifndef CLASSA_H
#define CLASSA_H

#include <iostream>

class ClassA
{
private:
    int _age;
    std::string _name;
public:
    ClassA() = delete;
    ClassA(const ClassA&) = delete;
    ClassA(ClassA &&) = delete;
    ClassA& operator = (const ClassA&&) = delete;
    ClassA& operator = (const ClassA&) = delete;
    ~ClassA() {}
    ClassA(int age, std::string name);

    int getAge() const { return _age; }
    void setAge(int age_) { _age = age_; }

    std::string getName() const { return _name; }
    void setName(const std::string &name_) { _name = name_; }

    friend std::ostream &operator<<(std::ostream &os, const ClassA &rhs);
    
};

#endif // CLASSA_H
