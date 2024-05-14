#include "computer.h"
#include<iostream>
using namespace std;

void computer::admission(){
    student::add="Computer";
}

computer::computer(int id, string name, int entranceMarks):student(id, name, entranceMarks, "Computer"){}