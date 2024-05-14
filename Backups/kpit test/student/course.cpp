#include "course.h"
#include <iostream>
using namespace std;

course::course()
{
    this->courseName = "";
    this->courseCode = "";
    this->creditHours = 0;
}

course::course(string courseName, string courseCode, int creditHours)
{
    this->courseName = courseName;
    this->courseCode = courseCode;
    this->creditHours = creditHours;
}

void course::setCourseName()
{
    cout << "Enter Couse Name: ";
    cin >> courseName;
}

void course::setCourseCode()
{
    cout << "Enter Course Code: ";
    cin >> courseCode;
}

void course::setCreditHours()
{
    cout << "Enter Credit Hours: ";
    cin >> creditHours;
}

string course::getCourseName()
{
    return this->courseName;
}

string course::getCourseCode()
{
    return this->courseCode;
}

int course::getCreditHours()
{
    return this->creditHours;
}

void course::accept()
{
    cout << "Enter Couse Name: ";
    cin >> courseName;
    cout << "Enter Course Code: ";
    cin >> courseCode;
    cout << "Enter Credit Hours: ";
    cin >> creditHours;
}

ostream &operator<<(ostream &out, const course &c)
{
    out << "Course Name: " << c.courseName << endl;
    out << "Course Code: " << c.courseCode << endl;
    out << "Credit Hours: " << c.creditHours << endl;
    return out;
}