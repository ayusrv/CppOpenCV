#ifndef STUDENT
#define STUDENT

#include<iostream>
using namespace std;
class student{
    public:
        string name;
        int roll_no;
        float marks[5];
        student();
        student(string name, int roll_no, float marks[5]);
        student(const student &s);
        void setName();
        void setRoll();
        void setMarks();
        string getName();
        int getRoll();
        // float* getMarks();
        void accept();
        int calcGrade();
        friend ostream & operator <<(ostream &out, const student &s);
        ~student();
};

#endif