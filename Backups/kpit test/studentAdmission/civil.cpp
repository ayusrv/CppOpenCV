#include "civil.h"
#include<iostream>
using namespace std;

civil::civil(int id, string name, int entranceMarks):student(id, name, entranceMarks, "Civil"){}
void civil::admission(){
    student::add="Civil";
}