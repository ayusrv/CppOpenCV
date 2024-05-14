#include "Operation.h"

OperationPointer Operation::_solo_hero_obj = nullptr;

OperationPointer &Operation::getInstance()
{
    if(!_solo_hero_obj)
    {
        _solo_hero_obj.reset(new Operation());
        return _solo_hero_obj;
    }
    else{
        return _solo_hero_obj;
    }
}

void Operation::CreateObject(Container &data, EngineConatiner& ec)
{
    ec.push_back(Engine("123", 200, 500, EngineType::CRDI));
    ec.push_back(Engine("143", 280, 590, EngineType::TURBOCHARGED));
    ec.push_back(Engine("133", 250, 540, EngineType::MPFI));
    
    data.push_back(std::make_shared<Car>("120C", 120, ec[0]));
    data.push_back(std::make_shared<Car>("125C", 150, ec[1]));
    data.push_back(std::make_shared<Car>("127C", 180, ec[2]));
}

std::vector<std::reference_wrapper<Engine>> Operation::getEngine(Container &data)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty");
    }
    std::vector<std::reference_wrapper<Engine>> ans;
    for(CarPointer cp : data)
    {
        ans.push_back(cp->mCarEngine());
    }
    return ans;
}

bool Operation::engineTorque(Container &data)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty");
    }
    return std::all_of(
        data.begin(),
        data.end(),
        [](CarPointer& cp)
        {
            return cp->mCarEngine().get().engineTorque() > 120;
        }
    );
}

float Operation::averageHorsePower(Container &data, float price)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty");
    }

    int count =0;
    float sum = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float stval, CarPointer& cp)
        {
            if(cp->mPrice() > price)
            {
                count++;
                stval = stval + cp->mCarEngine().get().mHoursepower();
            }
            return stval;
        }
    );
    return sum/count;
}

EngineType Operation::findEngineType(Container &data, std::string reg_num)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty");
    }
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](CarPointer& cp)
        {
            return cp->mCarRegNum() == reg_num;
        }
    );
    return itr->get()->mCarEngine().get().mEngineType();
}

std::reference_wrapper<Engine> Operation::highestTorque(Container &data)
{
    if(data.empty())
    {
        throw EmptyConatinerException("Data is empty");
    }
    auto itr = std::max_element(
        data.begin(),
        data.end(),
        [](CarPointer& cp1, CarPointer& cp2)
        {
            return cp1->mCarEngine().get().mHoursepower() < cp2->mCarEngine().get().mHoursepower();
        }
    );
    return itr->get()->mCarEngine();
}
