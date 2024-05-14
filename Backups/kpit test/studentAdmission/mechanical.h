#ifndef MECHANICAL
#define MECHANICAL
#include "student.h"
#include<iostream>
class mechanical:public student{
    public:
        mechanical(int id, std::string name, int entranceMarks);
        void admission();
};

#endif