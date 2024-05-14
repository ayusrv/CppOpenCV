#include "Operation.h"

OperationPointer Operation::_solo_hero_obj{nullptr};

void Operation::createObjects(Container &data)
{
    data.push_back(std::make_shared<Engine>(EngineType::REGULAR, 55.0f, "ABC123", EngineCylinder::CYLINDER_4, 100.0f));
    data.push_back(std::make_shared<Engine>(EngineType::TURBOCHARGE, 65.0f, "XYZ123", EngineCylinder::CYLINDER_6, 120.0f));
    data.push_back(std::make_shared<Engine>(EngineType::REGULAR, 85.0f, "MNP123", EngineCylinder::CYLINDER_4, 90.0f));
}

std::string Operation::maxHorsePower(Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data Not Found!", std::future_errc::no_state);
    }
    int max = 0;
    std::string ans;
    for (EnginePointer e : data)
    {
        if (e->engineHorsePower() > max)
        {
            max = e->engineHorsePower();
            ans = e->engineNumber();
        }
    }
    return ans;
}

float Operation::avgEngineTorque(Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data Not Found!", std::future_errc::no_state);
    }
    int avg = 0;
    for (EnginePointer e : data)
    {
        avg += e->engineTorque();
    }
    return avg / data.size();
}

std::optional<std::array<float, 2>> Operation::firstLastInstances(Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data Not Found!", std::future_errc::no_state);
    }
    if(data.size()<2)
    throw IdNotFoundException("ID is less", std::future_errc::no_state);

    std::array<float ,2> res;
    res[0] = data[0]->engineHorsePower();
    res[0] = data[0]->engineHorsePower();
    if(res.size()<2) return std::nullopt;

    return res;
}

void Operation::Assign(int n)
{
    setN(n);
}

std::vector<EngineType> Operation::firstNInstances(Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data Not Found!", std::future_errc::no_state);
    }
    int _N=n();
    if (_N <= 0 || _N > data.size())
    {
        throw IdNotFoundException("Index Not Found!", std::future_errc::broken_promise);
    }
    std::vector<EngineType> ans;
    for (EnginePointer e : data)
    {
        if (_N == 0)
        {
            return ans;
        }
        ans.push_back(e->eType());
        _N--;
    }
    return ans;
}
