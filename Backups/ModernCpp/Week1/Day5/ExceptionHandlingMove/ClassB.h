#ifndef CLASSB_H
#define CLASSB_H

#include "ClassA.h"
#include <ostream>

class  ClassB
{
private:
    /* data */
    int _phNo;
    ClassA* _aClass;
public:
    ClassB() = delete;
    ClassB(const ClassB&) = delete;
    ClassB& operator = (const ClassB&) = delete;
    ClassB& operator = (ClassB&&) = delete;
    ClassB(const ClassB&&) = delete;
    ~ClassB();
    int phNo() const { return _phNo; }
    void setPhNo(int phNo) { _phNo = phNo; }
    ClassA* getAClass() const { return _aClass; }
    void setAClass(ClassA* aClass_) { _aClass = aClass_; }
    ClassB(int phNo, ClassA* aclass);
    friend std::ostream &operator<<(std::ostream &os, const ClassB &rhs);
    friend std::ostream &operator<<(std::ostream &os, const ClassB &rhs);
    
};

#endif // CLASSB_H