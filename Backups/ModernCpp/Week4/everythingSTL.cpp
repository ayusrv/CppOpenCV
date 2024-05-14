#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>

int main(){
    std::vector<int> data {1,2,3,4,5};
    float sum = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](int x, const int a)
        {
            return x+a;
        }
    );
    std::cout<<sum<<std::endl;
    auto findd = std::find_if(
        data.begin(),
        data.end(),
        [](int n)
        {
            return n%2==0;
        }
    );
    std::cout<<"Finded value: "<<*findd<<std::endl;

    std::cout<<std::boolalpha<<std::all_of(data.begin(),
    data.end(),
    [](int n)
    {
        return n%2==0;
    })<<std::endl;

    std::cout<<std::boolalpha<<std::any_of(
        data.begin(),
        data.end(),
        [](int n)
        {
            return n%2==0;
        }
    )<<std::endl;

    int a = std::count_if(
        data.begin(),
        data.end(),
        [](int n ){
            return n%2==0;
        }
    );

    std::cout<<"Count : "<<a<<std::endl;

    std::vector<int> res(data.size());
    auto itr = std::copy_if(
        data.begin(),
        data.end(),
        res.begin(),
        [](int n)
        {
            return n%2==0;
        }
    );

    res.resize(std::distance(res.begin(), itr));
    for(int i : res) std::cout<<i<<" "<<std::endl;

    auto maxi = std::max_element(
        data.begin(),
        data.end(),
        [](int a, int b)
        {
            return a<b;
        }
    );
    std::cout<<"Max Elemeny is: "<<*maxi<<std::endl;

    std::unordered_map<int , std::string> map;
    map.emplace(10,"AYush");
    map.emplace(20,"abh");
    map.emplace(30,"jih");
    map.emplace(40,"iiih");

    for(auto [key, value]: map)
    {   
        std::cout<<key<<" "<<value<<std::endl; //agar pointer ya smart pointer raha to *value
    }

    auto itr3 = std::find_if(
        map.begin(),
        map.end(),
        [](const std::pair<int, std::string>& p)
        {
            return p.first == 30;
        }
    );

    std::cout<<(*itr3).second<<std::endl;

}