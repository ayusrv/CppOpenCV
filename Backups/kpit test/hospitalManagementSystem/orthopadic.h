#ifndef ORTHOPADIC
#define ORTHOPADIC

#include "employee.h"
#include<iostream>
class orthopadic:public employee{
    protected:
        int sal;
    public:
        orthopadic(int id, int timeIn, int timeOut, char* name, int sal);
        void salary();
        void setSal();
        int getSal();
};

#endif