#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s){
// Write your code here.
    unordered_map<int,int> map;
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++) {
        if (map.find(s - arr[i]) != map.end()) {
            vector<int> vec;
            vec.push_back(s - arr[i]);
            vec.push_back(arr[i]);
            ans.push_back(vec);
        }else {
            map[arr[i]] = i;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
} 