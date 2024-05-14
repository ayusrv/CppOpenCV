#include "Functionalities.h"
#include "EmptyConatinerException.h"
#include "SizeExceed.h"
#include <thread>
#include <future>

int main()
{
    Container data;
    CreateObject(data);
    int n = 2;
    std::future<std::optional<std::list<EvCarPointer>>> f1 = std::async(&NInsatances, std::ref(data), n);
    std::optional<std::list<EvCarPointer>> ans;
    std::future<int> f2 = std::async(&CountInstances, std::ref(data));
    int count;
    std::future<int> f3 = std::async(&TopSpeed, std::ref(data), "120IC");
    int topspeed;
    std::future<bool> f4 = std::async(&PureEvPlatform, std::ref(data));
    bool pureEv;
    try
    {
        ans = f1.get();
        count = f2.get();
        topspeed = f3.get();
        pureEv = f4.get();
    }
    catch (EmptyConatinerException &ex)
    {
        std::cout << ex.what();
    }
    catch (SizeExceed &ex)
    {
        std::cout << ex.what();
    }

    if (ans.has_value())
    {
        for (EvCarPointer evp : ans.value())
        {
            std::cout << *evp << "\n";
        }
    }
    else
    {
        std::cout << "No instance found\n";
    }

    std::cout << "\nCount instances: " << count << "\n";
    std::cout << "\nTop speed: " << topspeed << "\n";
    std::cout << "\nPure Ev: " << std::boolalpha << pureEv << "\n";
}