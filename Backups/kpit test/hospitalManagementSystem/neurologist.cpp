#include "neurologist.h"
#include<iostream>
using namespace std;

neurologist::neurologist(int id, int timeIn, int timeOut, char* name, int sal):employee::employee(id, timeIn, timeOut, name){
    this->sal=sal;
}

void neurologist::setSal(){
    this->sal=250;
}

int neurologist::getSal(){
    return sal;
}

void neurologist::salary(){
    cout<<"Salary: "<<((employee::getTimeOut()-employee::getTimeIn())/100)*sal<<endl;
}