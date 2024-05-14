#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<int> s1 {11,12,11,13,11,14,10};
    for(int i : s1)
    {
        std::cout<<i<<" ";
    }
    auto pair = s1.insert(11);
    if(pair.second){
        std::cout<<"\nElement added\n";
    }else{
        std::cout<<"\nNot added\n";
    }

    pair = s1.insert(33);
    if(pair.second){
        std::cout<<"Element added\n";
    }else{
        std::cout<<"Not added\n";
    }
}