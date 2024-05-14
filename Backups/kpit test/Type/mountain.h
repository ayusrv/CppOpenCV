#ifndef MOUNTAIN
#define MOUNTAIN
#include<bits/stdc++.h>
using namespace std;

class Mountain{
    protected:
        int age;
        int latitude;
    public:
        // Mountain();
        void accept();
        int getAge();
        int getLatitude();
        friend ostream & operator << (ostream &out, Mountain &m);
};

#endif
