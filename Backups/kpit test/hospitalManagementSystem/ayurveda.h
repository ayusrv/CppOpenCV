#ifndef AYURVEDA
#define AYURVEDA

#include "employee.h"
#include<iostream>

class ayurveda:public employee{
    protected:
        int sal;
    public:
        ayurveda(int id, int timeIn, int timeOut, char* name, int sal);
        void setSal();
        int getSal();
        void salary();
};

#endif