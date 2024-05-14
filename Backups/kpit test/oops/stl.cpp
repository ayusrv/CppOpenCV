// An engineer will not call it a bug — it’s an undocumented feature
// Software and temples are much the same — first we build them, then we pray
// Knock, knock … Who’s there? … *very long pause* … Java

//oops conceps, pointer, const, static, constructor, reference, 
#include<bits/stdc++.h>
using namespace std;

void extendedPair(){
    pair<int, int> p={1,3};
    cout<<p.first<<" "<<p.second;
    pair<int, pair<int, int>> nesp={1,{2,3}};
    cout<<nesp.first<<" "<<nesp.second.first<<" "<<nesp.second.second;
    pair<int,int> arr[]={{1,2},{3,4},{5,6}};
    cout<<arr[1].first;
}

void extendedVectors(){
    vector<int> v;
    v.push_back(10); //Add element in the vector
    v.emplace_back(20); //Same as push_back but little fast
    vector<pair<int,int>> vec; //Making vector of pair
    vec.push_back({1,2}); //Adding elemnt into the pair in vector
    vec.emplace_back(1,2); //You do not have to prove the curly braces to add the elemnt just provide the element it will automatically do this for you
    vector<int> v1(5,100); //WIll make 5 size array of values 100 -> {100,100,100,100,100}
    vector<int>v2(v1); //Copy vector v1 into the v2
    v.push_back(30);
    v.emplace_back(40);
    v.emplace_back(50);
    for(auto it: v){
        cout<<it<<" ";
    }
    v.erase(v.begin()+1); //This will remove the 2nd element i.e first lement + 1 step
    v.erase(v.begin()+2,v.begin()+4); //This will rempve the 2nd and 3rd element you have the give the index+1 till you want to delete the elemnt [start, end]

    //Insert FUnction
    vector<int> vins(2,100); //[100,100];
    vins.insert(vins.begin(),300); //[300,100,100]
    vins.insert(vins.begin()+1,2,10); //[300,10,10,100,100]
    vector<int> copy(2,50); //50,50
    vins.insert(vins.begin(),copy.begin(),copy.end()); //[50,50,300,10,10,100,100]
    cout<<v.size();
    vins.pop_back(); //[50,50,300,10,10,100] Remmove last element
    v.swap(vins); //Swap the vlaue of vins and v
    vins.clear();
    cout<<endl;
    for(auto it: v){
        cout<<it<<" ";
    }
    int arr[] = {1, 2, 3, 4, 5};

    // Calculate the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Convert array to vector
    vector<int> vec(arr, arr + size);
}

void extendedPriorityQueue(){
    //Maximum heap
    priority_queue<int> pq;//Always store the value in the shorted order
    pq.push(10);//10
    pq.push(20);//20,10
    pq.push(8);//20,10,8
    pq.push(12);//20,12,10,8

    cout<<pq.top;//20
    pq.pop();//20
    cout<<pq.top();//12

    //Minimum heap
    priority_queue<int, vector<int,int>, greater<int>> pqv;
    pqv.push(10);//10
    pqv.push(20);//10,20
    pqv.push(8);//8,10,20
    pqv.push(12);//8,10,12,20
}

void extendedSet(){
    set<int> st;
    st.insert(1);//1
    st.insert(2);//1,2
    st.insert(2);//1,2 This will not store the repeated values
    st.insert(4);//1,2,4
    st.insert(3);//1,2,3,4 Store in the sorted order
    st.insert(7);//1,2,3,4,7
    st.insert(5);//1,2,3,4,5,7
    st.insert(9);//1,2,3,4,5,7,9
    st.erase(5);//1,2,3,4,7,9
    auto it1 = st.find(2);//return 1;
    auto it2 = st.find(4);//return 1;
    st.erase(it1,it2);//will return 1,4,7,9 2nd and 3rd index hata dega 4th nahi 


}
int main(){
    cout<<" HII";
    extendedPair();
    extendedVectors();
    extendedPriorityQueue();
}