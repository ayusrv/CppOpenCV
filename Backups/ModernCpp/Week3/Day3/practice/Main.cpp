#include "Functionalities.h"
#include <thread>
#include <future>
#include <array>
#include <mutex>
std::mutex m;

int main()
{
    std::array<std::thread, 2> tArr;
    Container data;
    try
    {

        std::promise<int> pr;
        std::future<int> ft = pr.get_future();
        std::future<int> res = std::async(GetData, std::ref(data), std::ref(ft));
        CreateObject(data);
        tArr[0] = std::thread(CalculateTaxPayable, std::ref(data));
        tArr[1] = std::thread(CallParentOperator, std::ref(data));

        pr.set_value(10);
        {
            std::unique_lock<std::mutex> ul(m);
            std::cout<<"Value got: "<<res.get()<<std::endl;
        }
        
        // {
        //     std::lock_guard<std::mutex> lg(m);
        //     std::cout<<"Future ref: "<<res.get()<<std::endl;
        // }
        for (std::thread &th : tArr)
        {
            if (th.joinable())
            {
                th.join();
            }
        }
    }
    catch (EmptyContainer &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}