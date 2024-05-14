#include "beach.h"
#include "customer.h"
#include "mountain.h"
#include "trip.h"

#include<bits/stdc++.h>
using namespace std;

int main(){
    int size=1;
    trip *t[size];
    for(int i=0;i<size;i++){
        trip *ptr = new trip();
        ptr->accept();
        t[i] = ptr;
    }
    for(int i=0;i<size;i++){
        cout<<*t[i];
    }
    for(int i=0;i<size;i++){
        delete t[i];
    }

    trip *tt = new trip[size];
    trip *pp = tt;
    for(int i=0;i<size;i++){
        pp->accept();
        tt[i] = *pp;
        pp++;
    }
    for(int i=0;i<size;i++){
        cout<<tt[i];
    }

    delete[] tt;
}