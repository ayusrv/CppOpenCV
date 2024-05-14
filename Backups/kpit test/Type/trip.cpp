#include "trip.h"
#include<bits/stdc++.h>
using namespace std;

class phExcep : public exception{
    public:
        const char* what(){
            return "Wrong Phone Number";
        }
};


void Date::accept(){
    cout<<"Enter Date in (dd/mm/yyyy) fromat: ";
    cin>>day;
    cin>>month;
    cin>>year;
}

trip::trip(){}

void trip::accept(){
    customer::accept();
    cout<<"Enter Budget of your trip: ";
    cin>>budget;
    cout<<"Enter Country where you wanna go: ";
    cin>>location;
    Date::accept();
    if(budget>4000){
        m.accept();
    }else{
        b.accept();
    }
}

int trip::getBudget(){
    return budget;
}

string trip::getLocation(){
    return location;
}

ostream & operator << (ostream &out, trip &t){
    try{
        if(t.getPhoneNum().length()!=10){
            phExcep pe;
            throw pe;
        }
        out<<"Name: "<<t.getCustomerName()<<endl;
        out<<"Aadhar: "<<t.getAadhar()<<endl;
        out <<"Phone Number: " << t.getPhoneNum() << endl;
        out<<"Budget: "<<t.budget<<endl;
        out<<"Location: "<<t.location<<endl;
        out<<"Date: "<<t.day<<"/"<<t.month<<"/"<<t.year<<endl;
        if(t.budget>4000){
            out<<t.m;
        }else{
            out<<t.b;
        }
    }
    catch(phExcep pe){
        cout<<pe.what()<<endl;
    }
    return out;
}