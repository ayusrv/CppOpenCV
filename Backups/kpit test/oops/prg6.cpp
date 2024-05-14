#include<iostream>
using namespace std;
int* fun(){
    int x=5;
    return &x;
}
int main(){
    int *p = fun();
    fflush(stdin);
    cout<<*p;
}
int add(int a, int b){
    return a+b;
}
int j=0;