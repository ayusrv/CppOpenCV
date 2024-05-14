#include "enrollment.h"
#include "student.h"
#include "course.h"
#include <bits/stdc++.h>
using namespace std;

enrollment::enrollment() : s(s), c(c){}

enrollment::enrollment(student &ss, course &cc, string enrollmentDate)
{
    s.name = ss.name;
    s.roll_no = ss.roll_no;
    for (int i = 0; i < 5; i++)
    {
        s.marks[i] = ss.marks[i];
    }
    c.courseName = cc.courseName;
    c.courseCode = cc.courseCode;
    c.creditHours = cc.creditHours;
    this->enrollmentDate = enrollmentDate;
}

void enrollment::setStudent()
{
    s.accept();
}

void enrollment::setCourse()
{
    c.accept();
}

void enrollment::setEnrollmentDate()
{
    cout << "Enter Enrollment Date: ";
    cin >> enrollmentDate;
}

student enrollment::getStudent()
{
    return s;
}

course enrollment::getCourse()
{
    return c;
}

string enrollment::getEnrollmentDate()
{
    return enrollmentDate;
}

void enrollment::accept()
{
    s.accept();
    c.accept();
    cout << "Enter Enrollment Date: ";
    cin >> enrollmentDate;
}

ostream &operator<<(ostream &out, enrollment &e)
{
    out<<"\n\n\n";
    out << e.s;
    out << e.c;
    out << "Enrollment Date: " << e.enrollmentDate << endl;
    return out;
}

enrollment::~enrollment(){
    cout<<"Enrollment Destructor"<<endl;
}