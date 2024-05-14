#include<iostream>
using namespace std;

enum days{sun,mon,tue,wed,thur,fri,sat};
class p1{
    enum days d1;
    public:
    p1(enum days d){
        d1=d;
    }
    enum days dis(){
        return d1;
    }
};
int main(){
    p1 pp(mon);
    enum days d2=pp.dis();
    switch (d2)
    {
    case 0: cout<<"Sunday";
        break;
    case 1:cout<<"Monday";
        break;
    case 2: cout<<"Tuesday";
        break;
    case 3: cout<<"Wednusday";
        break;
    case 4: cout<<"Thursaday";
        break;
    case 5: cout<<"Friday";
        break;

    default:
        cout<<"Saturday";
        break;
    }

    cout<<sizeof(d2);
}