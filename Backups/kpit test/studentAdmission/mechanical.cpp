#include "mechanical.h"
#include <iostream>
using namespace std;

void mechanical::admission(){
    student::add = "Mechnical";
}

mechanical::mechanical(int id, string name, int entranceMarks):student(id, name, entranceMarks,"Mechanical"){}