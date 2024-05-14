// main.cpp
#include "result.cpp"

#include<iostream>

using namespace std;

int main() {
    result r;
    r.setRoll(10);
    r.show();
    r.setVal(80.9, 90.9, 60.8);
    r.getVal();
    r.seVal(97.8);
    r.geVal();
    r.totalGrad();
    // r.chem=10;
    // r.maths=10;
    // r.phy=10;
    // r.roll_no=1;
    // r.physical=10;

    // cout<<"Marks "<<r.chem<<" "<<r.maths<<" "<<r.phy<<" "<<r.physical<<" "<<r.roll_no<<endl;

    return 0;
}