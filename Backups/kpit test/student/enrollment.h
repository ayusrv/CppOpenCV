#ifndef ENROLLMENT
#define ENROLLMENT

#include "student.h"
#include "course.h"
#include<iostream>
using namespace std;

class enrollment{
    public:
        student s;
        course c;
        string enrollmentDate;
        enrollment();
        enrollment(student &s, course &c, string enrollmentDate);
        void setStudent();
        void setCourse();
        void setEnrollmentDate();
        student getStudent();
        course getCourse();
        string getEnrollmentDate();
        void accept();
        friend ostream & operator << (ostream &out, enrollment &e);
        ~enrollment();
};

#endif