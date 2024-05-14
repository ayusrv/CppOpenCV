#ifndef STUDENT
#define STUDENT

#include <bits/stdc++.h>

class student {
private:
    int rollNo;
    std::string name;

public:
    student();
    student(int rollno, std::string name);
    ~student();
    void getName();
    void setName(std::string name);
    void getRollNo();
    void setRollNo(int rollno);
};

#endif
