#ifndef EMPLOYEE
#define EMPLOYEE

#include<iostream>
using namespace std;

class employee{
    protected:
        int id;
        char *name;
    public:
        int timeIn, timeOut;
        employee(int id, int timeIn, int timeOut, char* name);
        virtual void salary()=0;
        void setId(int id);
        void setTimeIn(int timeIn);
        void setTimeOut(int timeOut);
        void setName(char* name);
        int getId();
        int getTimeIn();
        int getTimeOut();
        char* getName();
        void display();
};

#endif