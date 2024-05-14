#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    cout<<s.top();
}