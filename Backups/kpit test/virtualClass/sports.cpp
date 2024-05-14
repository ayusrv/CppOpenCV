#include "sports.h"

#include<iostream>
using namespace std;

void sports::seVal(float physical){
    this->physical = physical;
}

void sports::geVal(){
    cout<<"Your Physical Marks: "<<physical<<endl;
}