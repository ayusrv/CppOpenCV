#include "student.h"
#include<iostream>
using namespace std;

void student::setRoll(int roll_no){
    this->roll_no = roll_no;
}

void student::show(){
    cout<<"Your Roll No is: "<<roll_no<<endl;
}