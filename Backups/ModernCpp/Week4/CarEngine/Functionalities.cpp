#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "Car.h"

void CreateObjects(Container &data)
{
    data.emplace(
        "c101",
        std::make_shared<Car>(
            "c101",
            600000.0f,
            "Dzire",
            std::make_shared<Engine>(
                300,
                110.0f),
            CarType::SEDAN));
    data.emplace(
        "c102",
        std::make_shared<Car>(
            "c102",
            700000.0f,
            "Ezire",
            std::make_shared<Engine>(
                400,
                120.0f),
            CarType::HATCHBACK));
    data.emplace(
        "c103",
        std::make_shared<Car>(
            "c103",
            800000.0f,
            "Fzire",
            std::make_shared<Engine>(
                500,
                130.0f),
            CarType::SUV));
}

// void DeleteObjects(const Container &data)
// {
//     if (data.empty())
//     {
//         throw EmptyContainerException("Data is Empty");
//     }
//     for (Car *c : data)
//     {
//         delete c->engine(); // due to composition rule !!
//         delete c;
//     }
// }

int TotalHorsepower(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::broken_promise, "Data is Empty");
    }
    int total = 0;
    total = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](int answer_upto_current_pointer, const std::pair<std::string, CarPointer> &row)
        {
            return answer_upto_current_pointer + row.second->engine()->horsepower();
        });

    return total;
}

bool IsContainerAllCarAbover7l(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::broken_promise, "Data is Empty");
    }

    return std::all_of(
        data.begin(),
        data.end(),
        [](const std::pair<std::string, CarPointer> &row)
        {
            return row.second->price() > 70000;
        });
}

EnginePointer EnginePointerToMinPriceCar(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::broken_promise, "Data is Empty");
    }
    // asssume the first data value as your min
    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](const std::pair<std::string, CarPointer> &row1,const std::pair<std::string, CarPointer> &row2)
        {
            return row1.second->price() < row2.second->price();
        });

    return (*itr).second->engine(); // agar Engine* hoga return type then return (*itr).second->engine().get();
}

float AverageEngineTorque(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::broken_promise, "Data is Empty");
    }
    int total = 0;
    int count=0;
    total = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](int answer_upto_current_pointer, const std::pair<std::string, CarPointer> &row)
        {
            if (row.second->engine())
            {
                count++;
                return answer_upto_current_pointer + row.second->engine()->torque();
            }
            throw EmptyContainerException(std::future_errc::no_state, "Kahli hai bhai");
        });
    return total / count;
}

std::string FindCarModelByID(const Container &data,const std::string carId)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::broken_promise, "Data is Empty");
    }
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string, CarPointer>& row)
        {
            return row.first == carId;
        }
    );
    if(itr==data.end())
    {
        throw IdNotFoundException("ID NOT FOUND!!");
    }
    return (*itr).second->model();
}
