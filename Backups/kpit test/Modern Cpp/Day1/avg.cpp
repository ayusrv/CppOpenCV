#include<bits/stdc++.h>
using namespace std;
struct toot{
    float avg;
    int total;
};

struct toot * ca(int num1, int num2){
    struct toot *val = new toot();
    val->total = num1+num2;
    val->avg = (num1+num2)/2;
    return val;
}

int main(){
    struct toot *t = ca(10,10);
    cout<<t->avg<<" ";
    cout<<t->total;
    return 0;

}