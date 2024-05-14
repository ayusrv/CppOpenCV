#include "student.h"
#include <bits/stdc++.h>
using namespace std;

student::student()
{
    name = nullptr;
    roll_no = 0;
    float marks[5] = {0};
}

student::student(string name, int roll_no, float marks[5])
{
    this->name = name;
    this->roll_no = roll_no;
    for (int i = 0; i < 5; i++)
    {
        this->marks[i] = marks[i];
    }
}

student::student(const student &s)
{
    // this->name = new char[strlen(s.name)+1];
    this->name = s.name;
    this->roll_no = s.roll_no;
    for (int i = 0; i < 5; i++)
    {
        this->marks[i] = s.marks[i];
    }
}

void student::setName()
{
    cout << "Enter Your Name: ";
    cin >> this->name;
}

void student::setRoll()
{
    cout << "Enter Your Roll Number: ";
    cin >> this->roll_no;
}

void student::setMarks()
{
    cout << "Enter Your Marks: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> marks[i];
    }
}

string student::getName()
{
    return this->name;
}

int student::getRoll()
{
    return this->roll_no;
}

void student::accept()
{
    cout << "Enter Your Name: ";
    cin >> this->name;
    cout << "Enter Your Roll Number: ";
    cin >> this->roll_no;
    cout << "Enter Your Marks: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> marks[i];
    }
}

int student::calcGrade()
{
    int average = 0;
    for (int i = 0; i < 5; i++)
    {
        average += marks[i];
    }
    return average / 5;
}

ostream &operator<<(ostream &out, const student &s)
{
    out << "Your Name: " << s.name << endl;
    out << "Your Roll Number: " << s.roll_no << endl;
    out << "Your Marks: " << endl;
    for (int i = 0; i < 5; i++)
    {
        out << s.marks[i] << endl;
    }
    return out;
}

student::~student(){
    cout<<"Destructor Called "<<endl;
}