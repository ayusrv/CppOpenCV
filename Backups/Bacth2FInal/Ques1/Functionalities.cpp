#include "Functionalities.h"
#include "EmptyConatinerException.h"
#include "SizeExceed.h"

void CreateObject(Container &data)
{
    data.push_back(std::make_shared<EvCar>("120IC", 150, Platform::IC_BASED, 2, 4, 250));
    data.push_back(std::make_shared<EvCar>("130IC", 160, Platform::IC_BASED, 3, 5, 220));
    data.push_back(std::make_shared<EvCar>("140IC", 170, Platform::IC_BASED, 1, 6, 230));
    data.push_back(std::make_shared<EvCar>("150IC", 180, Platform::PURE_EV, 2.7, 7, 260));
    data.push_back(std::make_shared<EvCar>("160IC", 190, Platform::PURE_EV, 2.8, 8, 290));
}

std::optional<std::list<EvCarPointer>> NInsatances(Container &data, int n)
{
    if(data.size()<0)
    {
        throw EmptyConatinerException("Data is empty");
    }
    if(n>data.size() || n<0)
    {
        throw SizeExceed("Size passed is wrong");
    }
    int i=0;
    std::list<EvCarPointer> ans;
    while(i!=n)
    {
        ans.push_back(data[i]);
        i++;
    }
    return ans;
}

int CountInstances(Container &data)
{
    if(data.size()<0){
        throw EmptyConatinerException("Data is empty");
    }
    int ans = std::count_if(
        data.begin(),
        data.end(),
        [](EvCarPointer& ep)
        {
            return ep->mChassisLength() > 2.7;
        }
    );
    return ans;
}

int TopSpeed(Container &data, std::string m_car_id)
{
    if(data.size()<0){
        throw EmptyConatinerException("Data is empty");
    }
    Container::iterator &&itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const EvCarPointer& ev)
        {
            return ev->mCarId() == m_car_id;
        }
    );
    if(itr == data.end())
    {   
        return 0;
    }
    return ((*itr)->mTopSpeed());
}

bool PureEvPlatform(Container &data)
{
    if(data.size()<0){
        throw EmptyConatinerException("Data is empty");
    }

    bool ans= std::any_of(
        data.begin(),
        data.end(),
        [](EvCarPointer& ev)
        {
            return ev->mPlatform() == Platform::PURE_EV;
        }
    );
    return ans;
}
