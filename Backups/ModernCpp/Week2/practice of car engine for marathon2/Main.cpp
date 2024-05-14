#include <iostream>
#include "Functionalities.h"
#include <vector>
#include <memory>

int main()
{
    std::vector<std::shared_ptr<Car>> data(2);
    std::vector<std::shared_ptr<Engine>> data1(2);
    // std::vector<Car*>data(2);
    // std::vector<Engine*>data1(2);
    createobject(data, data1);
    std::cout << *data[1];
    calculate_avg_horse_power(
        [](std::vector<std::shared_ptr<Engine>> data1)
        {
            int avg = 0;
            for (int i = 0; i < data1.size(); i++)
            {
                avg += data1[i]->horsepower();
            }
            return avg / data1.size();
        },
        data1);
}