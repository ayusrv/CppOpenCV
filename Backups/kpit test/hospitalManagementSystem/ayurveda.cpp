#include "ayurveda.h"
#include<iostream>
using namespace std;

ayurveda::ayurveda(int id, int timeIn, int timeOut, char* name, int sal):employee::employee(id, timeIn, timeOut, name){
    this->sal=sal;
}

void ayurveda::setSal(){
    this->sal = 150;
}

int ayurveda::getSal(){
    return sal;
}

void ayurveda::salary(){
    cout<<"Salary: "<<((employee::getTimeOut()-employee::getTimeIn())/100)*sal<<endl;
}