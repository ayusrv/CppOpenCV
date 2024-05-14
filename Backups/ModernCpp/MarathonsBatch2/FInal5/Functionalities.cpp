#include "Functionalities.h"

void CreateObject(Conatiner &data)
{
    data.push_back(std::make_shared<Vehicle>("123", 50000, VehicleCategory::PRIVATE, TransmissionType::AUTOMATIC, 30, true));
    data.push_back(std::make_shared<Vehicle>("124", 60000, VehicleCategory::PUBLIC, TransmissionType::MANUAL, 40, false));
    data.push_back(std::make_shared<Vehicle>("125", 70000, VehicleCategory::PRIVATE, TransmissionType::AMT, 50, true));
    data.push_back(std::make_shared<Vehicle>("126", 80000, VehicleCategory::GOVT, TransmissionType::AMT, 60, false));
}

TransmissionType *getTransmission(Conatiner &data, int n)
{
    TransmissionType* ans = new TransmissionType[n];
    int i = 0;
    for(VehiclePtr vp : data)
    {
        if(i>=n) break;
        ans[i++] = vp->mTransmissionType();
    }
    
    return ans;
}

PriorityQueue getPriority(Conatiner &data, std::function < bool(VehiclePtr vp1, VehiclePtr vp2)> fun)
{
    PriorityQueue pq(data.begin(), data.end(), fun);
    return pq;
}

std::unordered_set<float> getPrice(Conatiner &data)
{
    std::unordered_set<float> ans;
    std::for_each(data.begin(), data.end(), [&](VehiclePtr vp)
    {
        ans.insert(vp->mVehiclePrice());
    });

    return ans;
}

std::unordered_map<std::string, VehicleCategory> getCategory(Conatiner &data, std::future<int>& fut)
{
    std::unordered_map<std::string, VehicleCategory> res;
    int n = fut.get();
    auto endItr = std::next(data.begin(), n);
    std::for_each(data.begin(), endItr, [&](VehiclePtr vp)
    {
        res.emplace(vp->mVehicleId(), vp->mVehicleCategory());
    });
    return res;
}

Conatiner transformData(Conatiner& data)
{
    Conatiner res(data.size());

    std::transform(data.begin(), data.end(), res.begin(), [](const VehiclePtr vp)
    {
        VehiclePtr copy = std::make_shared<Vehicle>(*vp); // create a copy of the VehiclePtr object
        copy->setMBootSpace(copy->mBootSpace() + 20);   // modify the copy
        return copy;                                    // return the copy
    });

    return res;
}