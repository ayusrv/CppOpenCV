#ifndef TRIP
#define TRIP

#include "customer.h"
#include "mountain.h"
#include "beach.h"
#include <iostream>
using namespace std;

class Date{
    public:
        int day;
        int month; 
        int year;
        void accept();
};

class trip:public Date, public customer{
    protected:
        int budget;
        string location;
        Mountain m;
        Beach b;
        
    public:
        trip();
        void accept();
        int getBudget();
        string getLocation();
        Date getDate();
        friend ostream & operator << (ostream &out, trip &t);
};

#endif