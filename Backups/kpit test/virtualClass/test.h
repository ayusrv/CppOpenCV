#ifndef TEST
#define TEST

#include "student.h"
class test : virtual public student{
    protected:
    public:
        float maths, phy, chem;
        void getVal();
        void setVal(float,float,float);
};

#endif