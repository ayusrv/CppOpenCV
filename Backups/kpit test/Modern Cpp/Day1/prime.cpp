#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    if(num==2){
        cout<<"Prime";
        return 0;
    }
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            cout<<"Not prime";
            return 0;
        }
    }
    cout<<"Prime";
}