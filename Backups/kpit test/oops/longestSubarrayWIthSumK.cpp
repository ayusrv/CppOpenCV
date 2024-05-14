#include<bits/stdc++.h>
using namespace std;
int solve(int n, int arr[], int k){
    unordered_map<int, int> map;
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];

        if (sum == k) {
            maxLength = i + 1;
        } else if (map.find(sum - k) != map.end()) {
            maxLength = max(maxLength, i - map[sum - k]);
        }

        if (map.find(sum) == map.end()) {
            map[sum] = i;
        }
    }

    return maxLength;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<solve(n,arr,k);
}