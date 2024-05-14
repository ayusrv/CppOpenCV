#include "Functionalities.h"
#include <mutex>
std::mutex mt;

//Creating the object
void CreateObject(Container &data)
{   
    data[0] = std::make_shared<Car>("Maruti","12CS",Category::COMMUTE, 2000000, RimSize::INCH_14, 35);
    data[1] = std::make_shared<Car>("Honda","13CS",Category::TOURIST, 3000000, RimSize::INCH_18, 35);
    data[2] = std::make_shared<Car>("BMW","14CS",Category::SPORTS, 4000000, RimSize::INCH_15, 35);
}

//Making the thread ofr the price threshold
std::vector<CarPointer> PriceThreshold(Container &data, float price)
{
    std::lock_guard<std::mutex> lg(mt);
    if(data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    std::vector<CarPointer> prices;   
    for(CarPointer cp : data)
    {
        if(cp->price()>price)
        {
            prices.push_back(cp);
        }
    }
    return prices;
}

//Seacrching the chassis number
CarPointer CarFound(Container &data, std::string chassis_number)
{
    std::lock_guard<std::mutex> lg(mt);
    if(data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    for(CarPointer cp : data)
    {
        if(cp->chassisNumber()==chassis_number)
        {
            return cp;
        }
    }

    throw IdNotFound("No instacnes of Chassis number found");
}

//Printing the categories of the car
std::vector<CarPointer> CategoryMatch(Container &data, Category car_type)
{
    std::lock_guard<std::mutex> lg(mt);
    if(data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    std::vector<CarPointer> res;
    for(CarPointer cp : data)
    {
        if(cp->getCategory()==car_type)
        {
            res.push_back(cp);
        }
    }
    return res;
}

//Getting the average price of each segment
std::array<float, 4> AveragePrice(Container &data)
{
    std::lock_guard<std::mutex> lg(mt);
    if(data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    float f1=0, f2=0, f3=0, f4=0;
    for(CarPointer cp : data)
    {
        if(cp->tyreRimSime()==RimSize::INCH_14)
        {
            f1++;
        }
        else if(cp->tyreRimSime()==RimSize::INCH_15)
        {
            f2++;
        }
        else if(cp->tyreRimSime()==RimSize::INCH_16){
            f3++;
        }else{
            f4;
        }
    }
    std::array<float,4> res{f1,f2,f3,f4};
    return res;
}

//Cheking the pressure of the tyre
bool CheckPressure(Container &data)
{
    std::lock_guard<std::mutex> lg(mt);
    if(data.empty())
    {
        throw EmptyContainerException("No data available", std::future_errc::no_state);
    }
    for(CarPointer cp : data)
    {
        if(cp->expectedTyrePressure()<30 && cp->expectedTyrePressure()>40)
            throw TyrePressureExceeds("Tyre Pressure is more or less than the expected");
            
        if(cp->expectedTyrePressure() <= 30) return false;
    }
    return true;
}
