#ifndef STUDENT
#define STUDENT

#include<iostream>

enum branch{Civil, Mechanical, Computer};

class student{
    protected:
        int id;
        std::string name;
        int entranceMarks;
        branch b;
    public:
        std::string add;
        virtual void admission()=0;
        student(int id, std::string name, int entranceMarks, std::string add);
        void getVal();
        ~student();
};

#endif