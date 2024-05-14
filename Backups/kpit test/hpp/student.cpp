#include "student.h"
#include <bits/stdc++.h>
using namespace std;

student::student() {
    rollNo = 0;
    name = "";
}

student::~student() {
    cout << "Destructor called" << endl;
}

student::student(int rollno, string name) {
    this->rollNo = rollno;
    this->name = name;
}

void student::getName() {
    cout << this->name;
}

void student::setName(string name) {
    this->name=name;
}

void student::getRollNo() {
    cout << this->rollNo;
}

void student::setRollNo(int rollno) {
    this->rollNo = rollno;
}
