#ifndef BEACH
#define BEACH

#include<bits/stdc++.h>
using namespace std;

class Beach{
    protected:
        int age;
        int temp;
    public:
        // Beach();
        void accept();
        int getAge();
        int getTemp();
        friend ostream & operator << (ostream &out, Beach &b);
};

#endif