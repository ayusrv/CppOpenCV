#ifndef COMPUTER
#define COMPUTER

#include "student.h"
#include<iostream>

class computer:public student{
    public: 
        computer(int id, std::string name, int entranceMarks);
        void admission();
};

#endif