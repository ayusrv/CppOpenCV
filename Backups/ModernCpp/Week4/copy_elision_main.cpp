#include "copy_elision_employee.h"

CEmployee& Magic()
{
    CEmployee e1("Harshit", 79899, "Trainer", 10);
    return e1;
}

int main(){
    CEmployee emp(Magic());
    std::cout<<emp<<std::endl;
}


/*
    Without copy elision

    With copy elision
*/