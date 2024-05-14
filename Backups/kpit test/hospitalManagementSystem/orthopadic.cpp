#include "orthopadic.h"
#include<iostream>
using namespace std;

orthopadic::orthopadic(int id, int timeIn, int timeOut, char* name, int sal):employee(id, timeIn, timeOut, name){
    this->sal=sal;
}
void orthopadic::salary(){
    cout<<"Salary: "<<((employee::getTimeOut()-employee::getTimeIn())/100)*sal<<endl;
}

void orthopadic::setSal(){
    this->sal=200;
}

int orthopadic::getSal(){
    return sal;
}