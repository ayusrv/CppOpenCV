#include<bits/stdc++.h>
using namespace std;
void swap(int a, int b){
    int temp = a;
    a=b;
    b=temp;
}
int main(){
    int m1,m2,m3;
    cin>>m1>>m2>>m3;
    if(m1<40 || m2<40 || m3<40) 
    {
        cout<<"Fail";
        return 0;
    }
    int average=(m1+m2+m3)/3;
    if(average>=70) cout<<"Distinction";
    else if(average>=50) cout<<"First Class";
    else if(average>=40) cout<<"Second Class";
    int sume=0,sumo=0;
    for(int i=1;i<=10;i++){
        if(i%2==0) sume+=i;
        else sumo+=i;
    }
    cout<<"\n"<<sume<<" "<<sumo;

}