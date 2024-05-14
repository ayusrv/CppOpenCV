#ifndef NEUROLOGIST
#define NEUROLOGIST

#include "employee.h"
#include<iostream>

class neurologist:public employee{
    protected:
        int sal;
    public:
        neurologist(int id, int timeIn, int timeOut, char* name, int sal);
        void setSal();
        int getSal();
        void salary();
};

#endif