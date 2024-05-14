#include "student.h"
#include<bits/stdc++.h>
using namespace std;

student::student(int id, std::string name, int entranceMarks, std::string add){
    this->id = id;
    this->name = name;
    this->entranceMarks = entranceMarks;
    this->add = add;
}

void student::getVal(){
    cout<<"Your id is: "<<id<<endl
        <<"Your name is: "<<name<<endl
        <<"Your entrance marks is: "<<entranceMarks<<endl
        <<"Your branch is: "<<add<<endl;
}

student::~student(){
    cout<<"Destructor"<<endl;
}