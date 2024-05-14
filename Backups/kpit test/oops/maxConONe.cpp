#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int m){
    int i=0,j=0;
    int mx=0;
    while(i<n && j<n){
        if(m==0 && arr[j]==0){
            mx=max(mx,j-i);
            i++;
            while(i<n && arr[i]==1) i++;
            m++;
        }
        else if(arr[j]==0){
            m--;
            j++;
        }
        else if(arr[j]==1){
            j++;
        }
    }
    return max(mx,j-i);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int m;
    cin>>m;
    cout<<solve(arr,n,m);
}
