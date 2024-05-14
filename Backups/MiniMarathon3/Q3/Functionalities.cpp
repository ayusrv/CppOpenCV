#include "Functionalities.h"
std::mutex m;

void CreateObject(Container &data)
{
    data.push_back(std::make_shared<EvCar>(10, ChassisType::LADDER, BatteryType::LI_ION, 34));
    data.push_back(std::make_shared<EvCar>(10, ChassisType::LADDER, BatteryType::LI_ION, 35));
    data.push_back(std::make_shared<ICECar>(10, ChassisType::LADDER, FuelType::DIESEL, 36));
    data.push_back(std::make_shared<ICECar>(10, ChassisType::LADDER, FuelType::PETROL, 37));
}

//Getting the NInstances
void NInstances(Container &data, ClassType type, int n)
{
    std::lock_guard<std::mutex> lg(m);
    if (data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    if (type == ClassType::EvCar_TYPE)
    {
        std::vector<EvCarPointer> res;
        for (VType v : data)
        {
            if (std::holds_alternative<EvCarPointer>(v))
            {
                if (n == 0)
                {
                    break;
                }
                EvCarPointer ev = std::get<EvCarPointer>(v);
                res.push_back(ev);
                n--;
            }
        }

        for(EvCarPointer e : res)
        {
            std::cout<<*e<<std::endl;
        }

        if (n != 0)
        {
            throw SizeExceedException("Size is exceeded");
        }
    }
    else if(type == ClassType::ICECar_TYPE)
    {
        std::vector<ICECarPointer> res;
        for (VType v : data)
        {
            if (std::holds_alternative<ICECarPointer>(v))
            {
                if (n == 0)
                {
                    break;
                }
                ICECarPointer ev = std::get<ICECarPointer>(v);
                res.push_back(ev);
                n--;
            }
        }

        if (n != 0)
        {
            throw SizeExceedException("Size is exceeded");
        }
        for(ICECarPointer ic : res)
        {
            std::cout<<*ic<<std::endl;
        }
    }
    else{
        throw TypeNotFound("Type not found ");
    }
}

// Checkng the fuel tank capacity
bool TankCapacity(Container &data)
{
    std::lock_guard<std::mutex> lg(m);
    if (data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    for(VType v : data)
    {
        if(std::holds_alternative<ICECarPointer>(v))
        {
            ICECarPointer ev = std::get<ICECarPointer>(v);
            if(ev->fuelTankCapacity()<30) return false;
        }
    }
    return true;
}

//Counting the ICE Cars in the variant
void CountICECar(Container &data)
{
    std::lock_guard<std::mutex> lg(m);
    if (data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    int count=0;
    for(VType v : data)
    {
        if(std::holds_alternative<ICECarPointer>(v))
        {
            count++;
        }
    }
    std::cout<<"Total ICE CARS are: "<<count<<std::endl;
}


EVCarContainer BatteryThreshold(Container &data, float threshold)
{
    std::lock_guard<std::mutex> lg(m);
    if (data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }

    EVCarContainer res;
    for(VType v : data)
    {
        if(std::holds_alternative<EvCarPointer>(v))
        {
            EvCarPointer ev = std::get<EvCarPointer>(v);
            if(ev->batteryCapacity()>threshold)
            {
                res.push_back(ev);
            }
        }
    }
    return res;
}

void Display(Container &data)
{
    std::lock_guard<std::mutex> lg(m);
    if (data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    float ans=0.0f;
    for(VType v : data)
    {
        if(std::holds_alternative<EvCarPointer>(v))
        {
            EvCarPointer ev = std::get<EvCarPointer>(v);
            if(ev->batteryCapacity()<20 && ev->batteryCapacity()>50)
            {
                throw BatteryCapacityExceed("Battery Capacity exceeds");
            }
            ans+=ev->batteryCapacity();
        }
    }
    std::cout<<"Battery Capacity is : "<<ans<<std::endl;
}

void DisplayNth(Container &data, int n)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty", std::future_errc::no_state);
    }
    if(n>=data.size())
    {
        throw SizeExceedException("Size is exceeding the limit");
    }
    std::visit([](auto&& args){
        std::cout<<*args;
    }, data[n]);
}
