#include <iostream>
#include <memory>
#include <future>

// Normal exception kaam nahi krega thread and async k saath



int fact(std::future<int> &ft)
{
    int *ptr = (int *)malloc(4);
    int n = ft.get(); // This thread will not get block till input comes
        if (n != 0)
        {
            int result = 1;
            for (int i = 2; i <= n; i++)
            {
                result *= i;
            }
            *ptr = result;
            std::cout << "Final answer is: " << *ptr << "\n";
            return *ptr;
        }
}

std::function<void(std::future<int> &)> factorial = [](std::future<int> &ft)
{
    int *ptr = (int *)malloc(4);
    int n = ft.get(); // This thread will not get block till input comes
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    *ptr = result;
    std::cout << "Final answer is: " << *ptr << "\n";
    // return *ptr;
};

int main()
{
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    std::future<int> result = std::async(&fact, std::ref(ft));
    std::future<void> result2 = std::async(factorial, std::ref(ft));
    int value = 0;
    std::cin >> value;
    pr.set_value(value);
    result.wait(); // THread mai join hota hai async mai wait hota hai
    result2.wait();
    std::cout << "Main ends" << std::endl;
}