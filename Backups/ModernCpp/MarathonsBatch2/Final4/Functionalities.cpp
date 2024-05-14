#include "Functionalities.h"

std::function<void(Conatiner &data)> CreateObject = [](Conatiner &data)
{
    data.push_back(std::make_shared<EvCar>("123", "Honda", 630000, EPowerType::ELECTRIC, BatteryType::LI_ON));

    data.push_back(std::make_shared<EvCar>("124", "BMW", 540000, EPowerType::HYBRID, BatteryType::NICAD));

    data.push_back(std::make_shared<ICECar>("125", "Dodge", 750000, EngineType::DIESEL));

    data.push_back(std::make_shared<ICECar>("126", "FOrd", 460000, EngineType::PETROL));
};  


std::function<Conatiner(Conatiner &data)> FindInstances = [](Conatiner &data)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty", std::future_errc::broken_promise);
    }
    std::vector<VType> result;
    std::insert_iterator<Conatiner> itr = std::copy_if(
        data.begin(),
        data.end(),
        std::inserter(result, result.begin()),
        [](VType &v)
        {
            return std::visit([](auto &&args)
                              { return args->price() < 600000; }, v);
        });
    return result;
};

std::function<float(Conatiner &data)> AveragePrice = [](Conatiner &data) {
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty", std::future_errc::broken_promise);
    }
    int count = 0;
    float sum = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float startVal, VType& v)
        {
            float tot = 0;
            if(std::holds_alternative<EvCarPtr>(v))
            {
                EvCarPtr eptr = std::get<EvCarPtr>(v);
                tot = eptr->price();
                count++;
            }
            return startVal + tot;
        }
    );
    return sum/count;
};

std::function<int(Conatiner& data, EPowerType engine_type)> CountEvCar = [](Conatiner& data, EPowerType engine_type)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty", std::future_errc::broken_promise);
    }
    return std::count_if(
        data.begin(),
        data.end(),
        [&](VType& v)
        {
            bool flag = false;
            if(std::holds_alternative<EvCarPtr>(v))
            {
                EvCarPtr eptr = std::get<EvCarPtr>(v);
                flag = eptr->engineType() == engine_type;
            }
            return flag;
        }
    );
};

std::function<std::string(Conatiner& data, std::string id)> FindName = [](Conatiner& data, std::string id)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty", std::future_errc::broken_promise);
    }

    Conatiner::iterator itr = std::find_if(
        data.begin(),
        data.end(),
        [&](VType v)
        {
            return std::visit([&](auto&& args)
            {
                return args->id() == id;
            }, v);
        } 
    );

    VType var = *itr;
    std::string ans ;
    std::visit([&](auto&& args)
    {
        ans = args->brandName();
    }, var);
    return ans;
};

std::function<std::unordered_set<EPowerType>(Conatiner& data)> FindBattery = [](Conatiner& data)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty", std::future_errc::broken_promise);
    }
    std::unordered_set<EPowerType> result;
    std::for_each(
        data.begin(),
        data.end(),
        [&](VType v)
        {
            if(std::holds_alternative<EvCarPtr>(v))
            {
                EvCarPtr eptr = std::get<EvCarPtr>(v);
                result.emplace(eptr->engineType());
            }
        }
    );
    return result;
};

std::function<bool(Conatiner& data)> CheckPrice = [](Conatiner& data)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty", std::future_errc::broken_promise);
    }
    return std::all_of(
        data.begin(),
        data.end(),
        [](VType v)
        {
            bool flag = false;
            std::visit([&](auto&& args)
            {
                flag = args->price() > 60000;
            }, v);
            return flag;
        }
    );
};