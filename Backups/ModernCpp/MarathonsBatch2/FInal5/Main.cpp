#include "Functionalities.h"

int main()
{
    Conatiner data;
    CreateObject(data);
    TransmissionType* ans = getTransmission(data, 4);
    for(int i=0;i<4;i++)
    {
        std::cout<<static_cast<int>(ans[i])<<"\n";
    }
    PriorityQueue pq = getPriority(data, [](VehiclePtr vp1, VehiclePtr vp2)
    {
        return vp1->mBootSpace() < vp2->mBootSpace();
    });

    while(!pq.empty())
    {
        std::cout<<*pq.top()<<"\n";
        pq.pop();
    }

    std::unordered_set<float> prices = getPrice(data);
    std::for_each(prices.begin(), prices.end(), [](float i)
    {
        std::cout<<i<<" ";
    });
    std::cout<<"\n";
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    std::future<std::unordered_map<std::string, VehicleCategory>> ft4 = std::async(getCategory, std::ref(data), std::ref(ft));
    pr.set_value(3);
    std::unordered_map<std::string, VehicleCategory> res = ft4.get();
    for(auto[k,v] : res)
    {
        std::string category;
        if(v==VehicleCategory::GOVT) category = "Govt";
        else if(v==VehicleCategory::PRIVATE) category = "Public";
        else category = "Private";
        std::cout<<"Key-> "<<k<<" Value-> "<<category<<"\n";
    }

    Conatiner ress = transformData(std::ref(data));
    for(VehiclePtr vp : ress)
    {
        std::cout<<*vp<<"\n";
    }
    std::cout<<"\n\n\n\n";
    for(VehiclePtr vp : data)
    {
        std::cout<<*vp <<"\n";
    }
    
}