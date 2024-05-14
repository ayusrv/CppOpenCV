#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> v){
    int n = v.size(), k = 0;
    for (int i = 0; i < n; i++) {
        if (v[i-k] < 0) {
            v.push_back(v[i - k]);
            v.erase(v.begin() + i - k);
            k++;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v(arr,arr+n);
    solve(v);
}