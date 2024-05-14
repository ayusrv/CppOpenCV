#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=1,b=1;
    int num;
    cin>>num;
    int sum=0;
    cout<<a<<" "<<b<<" ";
    while(num-->2){
        sum = a+b;
        cout<<sum<<" ";
        a=b;
        b=sum;
    }
}