#include "test.h"

#include<iostream>
using namespace std;

void test::setVal(float maths, float phy, float chem){
    this->maths = maths;
    this->phy = phy;
    this->chem = chem;
}

void test::getVal(){
    cout<<"Your marks "<<endl
        <<"Maths: "<<maths<<endl
        <<"Physics: "<<phy<<endl
        <<"Chemistry: "<<chem<<endl;
}
