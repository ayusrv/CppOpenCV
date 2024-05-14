#include "Functionalities.h"
#include <mutex>
std::mutex mt;

//Creating the object
void CreateObject(MapContainer &data)
{   
    data.emplace("12CS", std::make_shared<Car>("Maruti","12CS",Category::COMMUTE, 2000000, RimSize::INCH_14, 35));
    data.emplace("13CS", std::make_shared<Car>("Honda","13CS",Category::TOURIST, 3000000, RimSize::INCH_18, 35));
    data.emplace("14CS", std::make_shared<Car>("BMW","14CS",Category::SPORTS, 4000000, RimSize::INCH_15, 35));
}

//Making the thread ofr the price threshold
MapContainer PriceThreshold(MapContainer &data, float price)
{
    std::lock_guard<std::mutex> lg(mt);
    if(data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    MapContainer mp;
    auto itr = std::copy_if(data.begin(), data.end(), std::inserter(mp, mp.end()),[&](const std::pair<std::string, CarPointer>& c)
    {
        return c.second->price()>price;
    });
    
    return mp;
}

//Seacrching the chassis number
CarPointer CarFound(MapContainer &data, std::string chassis_number)
{
    std::lock_guard<std::mutex> lg(mt);
    if(data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string, CarPointer>& p)
        {
            return p.first==chassis_number;
        }
    );
    if(itr!=data.end())
    {
        return itr->second;
    }

    throw IdNotFound("No instacnes of Chassis number found");
}

//Printing the categories of the car
MapContainer CategoryMatch(MapContainer &data, Category car_type)
{
    std::lock_guard<std::mutex> lg(mt);
    if(data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    MapContainer res;
    auto itr = std::copy_if(data.begin(), data.end(), std::inserter(res, res.end()), [&](const std::pair<std::string, CarPointer>& c){
        return c.second->getCategory()==car_type;
    });
    return res;
}

//Getting the average price of each segment
std::array<float, 4> AveragePrice(MapContainer &data)
{
    std::lock_guard<std::mutex> lg(mt);
    if(data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    float f1=0, f2=0, f3=0, f4=0;
    f1 = std::count_if(data.begin(), data.end(), [](const std::pair<std::string, CarPointer>&c ){
        return c.second->tyreRimSime()==RimSize::INCH_14;
    });
    f2 = std::count_if(data.begin(), data.end(), [](const std::pair<std::string, CarPointer>&c ){
        return c.second->tyreRimSime()==RimSize::INCH_15;
    });
    f3 = std::count_if(data.begin(), data.end(), [](const std::pair<std::string, CarPointer>&c ){
        return c.second->tyreRimSime()==RimSize::INCH_16;
    });
    f4 = std::count_if(data.begin(), data.end(), [](const std::pair<std::string, CarPointer>&c ){
        return c.second->tyreRimSime()==RimSize::INCH_18;
    });
    // for(CarPointer cp : data)
    // {
    //     if(cp->tyreRimSime()==RimSize::INCH_14)
    //     {
    //         f1++;
    //     }
    //     else if(cp->tyreRimSime()==RimSize::INCH_15)
    //     {
    //         f2++;
    //     }
    //     else if(cp->tyreRimSime()==RimSize::INCH_16){
    //         f3++;
    //     }else{
    //         f4;
    //     }
    // }
    std::array<float,4> res{f1,f2,f3,f4};
    return res;
}

//Cheking the pressure of the tyre
// bool CheckPressure(MapContainer &data)
// {
//     std::lock_guard<std::mutex> lg(mt);
//     if(data.empty())
//     {
//         throw EmptyContainerException("No data available", std::future_errc::no_state);
//     }
//     for(CarPointer cp : data)
//     {
//         if(cp->expectedTyrePressure()<30 && cp->expectedTyrePressure()>40)
//             throw TyrePressureExceeds("Tyre Pressure is more or less than the expected");
            
//         if(cp->expectedTyrePressure() <= 30) return false;
//     }
//     return true;
// }
