#ifndef CLASSB_H
#define CLASSB_H

#include <iostream>
#include <memory>
#include "ClassA.h"

class ClassB
{
private:
    int ptr;
public:
    ClassB(/* args */) {}
    ~ClassB() {}

    std::shared_ptr<ClassA> getPtr() const { return ptr; }
    void setPtr(const std::shared_ptr<ClassA> &ptr_) { ptr = ptr_; }

    friend std::ostream &operator<<(std::ostream &os, const ClassB &rhs);

    ClassB(std::shared_ptr<ClassA>);
    
};

#endif // CLASSB_H
