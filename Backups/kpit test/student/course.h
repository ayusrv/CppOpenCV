#ifndef COURSE
#define COURSE

#include "student.h"
#include<iostream>
using namespace std;

class course{
    public:
        string courseName;
        string courseCode;
        int creditHours;
        course();
        course(string courseName, string courseCode, int creditHours);
        void setCourseName();
        void setCourseCode();
        void setCreditHours();
        string getCourseName();
        string getCourseCode();
        int getCreditHours();
        void accept();
        friend ostream & operator <<(ostream &out,const course &c);
};

#endif