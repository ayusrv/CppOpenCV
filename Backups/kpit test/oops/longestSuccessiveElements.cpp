#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&a) {
    // Write your code here.
    set<int> s;
    for(int i=0;i<a.size();i++){
        s.insert(a[i]);
    }
    unordered_map<int,int> map;
    for(int i=0;i<s.size();i++){
        if()
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + size);
    cout<<solve(vec);
}