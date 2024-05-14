#include "classB.h"
#include <iostream>
#include "Functionalities.h"
void createObject(classB* &b){
    b = new classB(new classA(10,20), 30);
}

void displayObject(classB* &data)
{
    std::cout<<data->getA()->age();
}
void deleteObject(classB* &b)
{
    delete b->getA();
    delete b;
}