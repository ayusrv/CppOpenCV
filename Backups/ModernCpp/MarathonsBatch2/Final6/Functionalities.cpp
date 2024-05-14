#include "Functionalities.h"

void CreateObject(Container &data)
{
    data.push_back(std::make_shared<CabDriver>("Ayush", 20, 560, "OLA", CarType::HATCHBACK, 4));
    data.push_back(std::make_shared<CabDriver>("Rohan", 30, 580, "UBER", CarType::SUV, 3));
    data.push_back(std::make_shared<CabDriver>("Suraj", 40, 600, "IN DRIVER", CarType::SEDAN, 4));
    data.push_back(std::make_shared<CabDriver>("ROhit", 50, 670, "Rapido", CarType::HATCHBACK, 2));
}

std::optional<std::unordered_set<CabDriverPtr>> getFunctions(Container &data, std::vector<std::function<bool(const CabDriverPtr cp1)>> functions)
{
    std::unordered_set<CabDriverPtr> res;

    // std::for_each(data.begin(), data.end(), [&](CabDriverPtr cp1)
    // {
    //     bool flag = fun(cp1);
    //     if(flag){
    //         res.insert(cp1);
    //     }
    // });
    
    std::for_each(data.begin(),data.end(),[&](const CabDriverPtr ptr){
        bool flag=true;
        std::for_each(functions.begin(),functions.end(),[&](std::function<bool(const CabDriverPtr)> fn){
            if(!fn(ptr)){
                flag=false;
            }

        });
        if(flag){
            res.insert(ptr);
        }
    });


    if(res.empty()) return std::nullopt;
    return res;
}

void checkPair(Container &data, std::pair<std::string, int> &pr, int n)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty", std::future_errc::broken_promise);
    }
    pr.first = data[n]->name();
    pr.second = data[n]->km();
}

PriorityQueue PriorityValues(Container &data, std::function<bool(CabDriverPtr& cp1, CabDriverPtr& cp2)> fun)
{
    PriorityQueue pq(data.begin(), data.end(), fun);
    
    return pq;
}
