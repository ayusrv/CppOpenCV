#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"ENter value of A and B: ";
    cin>>a>>b;
    int x=a-b;
    try{
        if(x!=0) cout<<"Result (a/x) = "<<a/x<<"\n";
        else throw(x);
    }
    catch(int i){
        cout<<"Exception Countered: X = "<<x<<"\n";
    }
    cout<<"END";
}