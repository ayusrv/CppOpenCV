#ifndef CLASSB_H
#define CLASSB_H

#include "classA.h"

class classB
{
private:
    classA* _a;
    int abc {0};
public:
    classB()=default;

    classB(classA* a, int aa):_a{a}, abc{aa} {}
    
    ~classB()=default;

    classA* getA() const { return _a; }
    void setA(classA* a_) { _a = a_; }
};

#endif // CLASSB_H
