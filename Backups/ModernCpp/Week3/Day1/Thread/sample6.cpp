/*
    create an array of 3 threads
        - thread 1 should calculate square of each number in the array and store in a result array (position 1 to 5)
        - thread 2 should calculate cube of each number in the array ad store in a result array (position 6 to 10)
        - thread 3 should calculate factorial of each number in the array and store in a result array (position 11 to 15)

        Assumption : NUmbers in the input array will be between 1 to 10

*/

#include <thread>
#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <mutex>
std::mutex mt;

using FType = std::function<void()>;
using FContainer = std::vector<FType>;
using Container = std::vector<int>;
using TContainer = std::vector<std::thread>;

int factorial(int num){
    if(num==0) return 1;
    return num*factorial(num-1);
}

void CreateObjects(FContainer& fns, Container& data, Container& result)
{
    fns.push_back([&](){
        for(int i : data){
            result.push_back(i*i);
        }
    });

    fns.push_back([&](){
        for(int i : data ){
            result.push_back(i*i*i);
        }
    });

    fns.push_back([&](){
        for(int i : data){
            result.push_back(factorial(i));
        }
    });
}

void MapObject(TContainer& tArr, FContainer& fns){
    
}

int main()
{
    std::array<int, 15> result;
    int i = 0, j = 5, k=10;
    std::vector<int> v{1, 2, 3, 4, 5};
    auto f1 = [&]()
    {
            for (int number : v)
            {
                result[i] = number * number;
                i++;
            }
    };
    auto f2 = [&]()
    {
            for (int number : v)
            {
                result[j] = number * number * number;
                j++;
            }
    };
    auto f3 = [&]()
    {
        int l = 2;
        result[k] = 1;
        k++;
        while (l < 6)
        {
            result[k] = result[k - 1] * l;
            l++;
            k++;
        }
    };
    std::array<std::thread, 3>
        arr{std::thread(f1), std::thread(f2), std::thread(f3)};

    try
    {
        for (std::thread &t : arr)
        {
            if (t.joinable())
            {
                t.join();
            }
            else
            {
                throw std::runtime_error("Run time error");
            }
        }
        for (int x : result)
        {
            std::cout << x << " ";
        }
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}