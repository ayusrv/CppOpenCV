#include<vector>
int main(){
    std::vector<int> v1 {1,2,3,4,5};
    auto itr = v1.begin();

    decltype(v1)v2 {1,2,3,4,5,6};
    //Isme hum v1 ka data type ko v2 mai daal diye hai 
    //ye v auto k tarah hota hai but isme phele se type predefined hota hai guess nahi hota hai
}