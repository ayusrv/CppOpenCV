#ifndef SPORTS
#define SPORTS

#include "student.h"

class sports: virtual public student{
    protected:
    public:
    float physical;
        void seVal(float);
        void geVal();
};

#endif