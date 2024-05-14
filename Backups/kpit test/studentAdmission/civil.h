#ifndef CIVIL
#define CIVIL

#include "student.h"
#include <iostream>

class civil:public student{
    public:
        civil(int id, std::string name, int entranceMarks);
        void admission();
};

#endif