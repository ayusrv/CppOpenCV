#include "Functionalities.h"

int main()
{
    MapContainer data;

    //Creating the object
    std::future<void> create = std::async(CreateObject, std::ref(data));
    create.get();
    try
    {
        //Making the thread ofr the price threshold
        float price = 300000;
        std::future<MapContainer> PThreshold = std::async(PriceThreshold, std::ref(data), std::ref(price));
        std::cout<<"Printing the car whose prices are above: "<<std::endl;
        for(const std::pair<std::string, CarPointer>& cp : PThreshold.get())
        {
            std::cout<<*(cp.second)<<std::endl;
        }

        //Seacrching the chassis number
        std::string c_no = "12CS";
        std::future<CarPointer> CarFind = std::async(CarFound, std::ref(data), std::ref(c_no));
        std::cout<<"Printing the car whose chassis number found: "<<*CarFind.get()<<std::endl;

        //Printing the categories of the car
        Category c_type = Category::SPORTS;
        std::future<MapContainer> categories = std::async(CategoryMatch, std::ref(data), std::ref(c_type));
        std::cout<<"Printing the details whose categories matches: "<<std::endl;
        for(const std::pair<std::string, CarPointer>& cp : categories.get())
        {
            std::cout<<*(cp.second)<<std::endl;
        }

        //Getting the average price of each segment
        std::future<std::array<float, 4>> avg = std::async(AveragePrice, std::ref(data));
        std::cout<<"Printing the average price: "<<std::endl;
        for(float f : avg.get())
        {
            std::cout<<f<<" ";
        }
        std::cout<<std::endl;

        // //Cheking the pressure of the tyre
        // std::future<bool> pressure = std::async(CheckPressure, std::ref(data));
        // std::cout<<"Pressure is: "<<std::boolalpha<<pressure.get()<<std::endl;
    }
    catch(EmptyContainerException &ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
    catch(IdNotFound &ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
    catch(TyrePressureExceeds &ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
}