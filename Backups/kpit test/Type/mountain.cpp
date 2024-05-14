#include "mountain.h"
#include <bits/stdc++.h>

using namespace std;

// Mountain::Mountain():age(0),latitude(0){}

void Mountain::accept(){
    cout<<"Enter Your Age: ";
    cin>>age;
    cout<<"Enter the maximum height you can go: ";
    cin>>latitude;
}

int Mountain::getAge(){
    return age;
}

int Mountain::getLatitude(){
    return latitude;
}

ostream & operator << (ostream &out, Mountain &m){
    out<<"Your Age: "<<m.age<<endl;
    out<<"Maximum Height: "<<m.latitude<<endl;
    return out;
}