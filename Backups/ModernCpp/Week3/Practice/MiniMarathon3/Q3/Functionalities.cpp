#include "Functionalities.h"
std::mutex m;

void CreateObject(Container &data)
{
    data.push_back(std::make_shared<EvCar>(10, ChassisType::LADDER, BatteryType::LI_ION, 34));
    data.push_back(std::make_shared<EvCar>(10, ChassisType::LADDER, BatteryType::LI_ION, 35));
    data.push_back(std::make_shared<ICECar>(10, ChassisType::LADDER, FuelType::DIESEL, 36));
    data.push_back(std::make_shared<ICECar>(10, ChassisType::LADDER, FuelType::PETROL, 37));
}

// Getting the NInstances
void NInstances(Container &data, ClassType type, int n)
{

    Container result(data.size());

    auto itr = std::copy_if(data.begin(), data.end(), result.begin(),
                            [&](const VType &v)
                            {
                                bool flag = false;
                                if (type == ClassType::EvCar_TYPE)
                                {
                                    if (std::holds_alternative<EvCarPointer>(v))
                                    {
                                        flag = true;
                                    }
                                }
                                else
                                {
                                    if (std::holds_alternative<ICECarPointer>(v))
                                    {
                                        flag = true;
                                    }
                                }
                                return flag;
                            });

    result.resize(std::distance(result.begin(), itr));

    for (VType &v : result)
    {
        std::visit([](auto &&val)
                   { std::cout << "888" << *val << std::endl; },
                   v);
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

    bool flag = std::all_of(data.begin(), data.end(),
                            [](const VType &v)
                            {
                                bool flag2 = true;
                                if (std::holds_alternative<ICECarPointer>(v))
                                {
                                    ICECarPointer temp = std::get<1>(v);
                                    flag2 = temp->fuelTankCapacity()>30;
                                    
                                }
                                return flag2;
                            });


    return flag;
    //     for (VType v : data)
    // {
    //     if (std::holds_alternative<ICECarPointer>(v))
    //     {
    //         ICECarPointer ev = std::get<ICECarPointer>(v);
    //         if (ev->fuelTankCapacity() < 30)
    //             return false;
    //     }
    // }
    // return true;
}

// Counting the ICE Cars in the variant
void CountICECar(Container &data)
{
    std::lock_guard<std::mutex> lg(m);
    if (data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    int count = 0;
    count = std::count_if(data.begin(), data.end(),
                          [&](VType &v)
                          {
                              return std::holds_alternative<ICECarPointer>(v);
                          });
    // for (VType v : data)
    // {
    //     if (std::holds_alternative<ICECarPointer>(v))
    //     {
    //         count++;
    //     }
    // }
    std::cout << "Total ICE CARS are: " << count << std::endl;
}

Container BatteryThreshold(Container &data, float threshold)
{
    std::lock_guard<std::mutex> lg(m);
    if (data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }

    Container res(data.size());
    auto itr = std::copy_if(data.begin(), data.end(), res.begin(),[&](const VType& v)
    {
        bool flag=false;
        if(std::holds_alternative<EvCarPointer>(v))
        {
            EvCarPointer ev = std::get<EvCarPointer>(v);
            flag=ev->batteryCapacity()>threshold;
        }
        return flag;
    });
    res.resize(std::distance(res.begin(), itr));
    // for (VType v : data)
    // {
    //     if (std::holds_alternative<EvCarPointer>(v))
    //     {
    //         EvCarPointer ev = std::get<EvCarPointer>(v);
    //         if (ev->batteryCapacity() > threshold)
    //         {
    //             res.push_back(ev);
    //         }
    //     }
    // }
    return res;
}

void Display(Container &data)
{
    std::lock_guard<std::mutex> lg(m);
    if (data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    // float ans = 0.0f;
    auto ans = std::accumulate(data.begin(), data.end(), 0.0f,[](float a , const VType& v)
    {
        float val=0.0f;
        if(std::holds_alternative<EvCarPointer>(v))
        {
            EvCarPointer ev = std::get<EvCarPointer>(v);
            if (ev->batteryCapacity() < 20 && ev->batteryCapacity() > 50)
            {
                throw BatteryCapacityExceed("Battery Capacity exceeds");
            }
            val= a + ev->batteryCapacity();
        }
        return val;
    });
    // for (VType v : data)
    // {
    //     if (std::holds_alternative<EvCarPointer>(v))
    //     {
    //         EvCarPointer ev = std::get<EvCarPointer>(v);
    //         if (ev->batteryCapacity() < 20 && ev->batteryCapacity() > 50)
    //         {
    //             throw BatteryCapacityExceed("Battery Capacity exceeds");
    //         }
    //         ans += ev->batteryCapacity();
    //     }
    // }
    std::cout << "Battery Capacity is : " << ans << std::endl;
}

void DisplayNth(Container &data, int n)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty", std::future_errc::no_state);
    }
    if (n >= data.size())
    {
        throw SizeExceedException("Size is exceeding the limit");
    }
    std::visit([](auto &&args)
               { std::cout << *args; },
               data[n]);

    std::cout<<"\n";
}
