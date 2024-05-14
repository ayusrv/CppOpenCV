#include "Functionalities.h"
#include <future>

int main()
{
    Conatiner data;
    CreateObject(data);

    std::future<Conatiner> ft1 = std::async(FindInstances, std::ref(data));
    std::future<float> ft2 = std::async(AveragePrice, std::ref(data));
    std::future<int> ft3 = std::async(CountEvCar, std::ref(data), EPowerType::ELECTRIC);
    std::future<std::string> ft4 = std::async(FindName, std::ref(data), "123");
    std::future<std::unordered_set<EPowerType>> ft5 = std::async(FindBattery, std::ref(data));
    std::future<bool> ft6 = std::async(CheckPrice, std::ref(data));

    try
    {
        Conatiner result = ft1.get();
        std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
        std::for_each(result.begin(), result.end(), [](VType &v)
                      { std::visit([](auto &&args)
                                   { std::cout << *args << "\n"; }, v); });

        std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
        float avg = ft2.get();
        std::cout << "Average Price of EvCar is: " << avg << "\n";

        std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
        int count = ft3.get();
        std::cout << "Total EvCarPtr are -> " << count << "\n";

        std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
        std::cout << "Brand name of the id provided is: " << ft4.get() << "\n";

        std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
        std::unordered_set<EPowerType> EPType = ft5.get();
        std::for_each(EPType.begin(), EPType.end(), [](EPowerType ep)
                      {
        if(ep==EPowerType::ELECTRIC) std::cout<<"ELECTRIC\n";
        else std::cout<<"HYBRID\n"; });

        std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
        bool checkData = ft6.get();
        std::cout << "All data abouve 60 Thousands? " << std::boolalpha << checkData << "\n";

        std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
    }
    catch(EmptyConatinerException &ex)
    {
        std::cout<<ex.what()<<"\n";
    }
}