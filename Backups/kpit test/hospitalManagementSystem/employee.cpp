#include "employee.h"
#include<iostream>
using namespace std;

employee::employee(int id, int timeIn, int timeOut, char* name){
    this->id=id;
    this->timeIn=timeIn;
    this->timeOut=timeOut;
    this->name = name;
}

void employee::display(){
    cout<<"Employee id: "<<id<<endl
        <<"Employee Name: "<<name<<endl
        <<"Time In: "<<timeIn<<endl
        <<"Time Out: "<<timeOut<<endl;
}

void employee::setId(int id){
    this->id=id;
}

void employee::setName(char* name){
    this->name=name;
}

void employee::setTimeIn(int timeIn){
    this->timeIn = timeIn;
}

void employee::setTimeOut(int timeOut){
    this->timeOut = timeOut;
}

int employee::getId(){
    return id;
}

int employee::getTimeIn(){
    return timeIn;
}

int employee::getTimeOut(){
    return timeOut;
}

char* employee::getName(){
    return name;
}