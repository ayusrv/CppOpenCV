#include "Operation.h"
#include <future>
#include <thread>

int main()
{
    std::unique_ptr<Operation>& op = Operation::getInstance();
    
    Container data;
    EngineConatiner ec;
    
    op->CreateObject(data, ec);
    
    std::future<std::vector<std::reference_wrapper<Engine>>> fut1 = std::async(&Operation::getEngine, op.get(), std::ref(data));
    
    std::future<bool> fut3 = std::async(&Operation::engineTorque, op.get(), std::ref(data));

    std::future<float> fut2 = std::async(&Operation::averageHorsePower, op.get(), std::ref(data), 149);

    std::future<EngineType> fut4 = std::async(&Operation::findEngineType, op.get(), std::ref(data), "120C");

    std::future<std::reference_wrapper<Engine>> fut5 = std::async(&Operation::highestTorque, op.get(), std::ref(data));



    std::vector<std::reference_wrapper<Engine>> ans1 = fut1.get();
    for(Engine& e : ans1)
    {
        std::cout<<e<<"\n";
    }

    std::cout<<"All engine torque is more than 120 or not: "<<std::boolalpha<<fut3.get()<<"\n";

    float ans = fut2.get();
    std::cout<<ans<<"\n";

    EngineType et = fut4.get();
    std::cout<<"Engine type with given registration number is: "<<data[0]->mCarEngine().get().EnumToString(et)<<"\n";

    std::reference_wrapper<Engine> refE = fut5.get();
    std::cout<<"HIghest torque data: "<<refE<<"\n";
}