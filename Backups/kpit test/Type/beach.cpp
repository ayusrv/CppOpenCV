#include "beach.h"
#include<bits/stdc++.h>
using namespace std;

// Beach::Beach():age(0),temp(0){}

void Beach::accept(){
    cout<<"Enter your age: ";
    cin>>age;
    cout<<"Enter the temperature you want: ";
    cin>>temp;
}

int Beach::getAge(){
    return age;
}

int Beach::getTemp(){
    return temp;
}

ostream & operator << (ostream &out, Beach &b){
    out<<"Age: "<<b.age<<endl;
    out<<"Temperature: "<<b.temp<<endl;
    return out;
}