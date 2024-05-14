#include "Functionalities.h"

int main()
{
    Container data;
    CreateObject(data);
    std::optional<std::unordered_set<CabDriverPtr>> res = getFunctions(data, [](CabDriverPtr& cp)
    {
        return cp->price() >= 600;
    });

    if(res.has_value())
    {
        std::unordered_set<CabDriverPtr> ans = res.value();
        // std::unordered_set<CabDriverPtr> ans1 = res.value();
        // for(CabDriverPtr cp : ans)
        // {
        //     std::cout<<*cp<<"\n";
        // }

        std::for_each(res.value().begin(), res.value().end(), [](const CabDriverPtr& cp1)
        {
            std::cout<<*cp1<<"\n";
        });
    }
    else{
        std::cout<<"No data presenty\n";
    }


    std::pair<std::string, int> pr;
    checkPair(data, pr, 2);
    std::cout<<pr.first<<" "<<pr.second<<"\n";

    std::function<bool(CabDriverPtr& cp1, CabDriverPtr& cp2)> fun = [](CabDriverPtr& cp1, CabDriverPtr& cp2)
    {
        return cp1->price() > cp2->price();
    };

    PriorityQueue pq = PriorityValues(data, fun);
    while(!pq.empty())
    {
        std::cout<<*pq.top()<<"\n";
        pq.pop();
    }
}
