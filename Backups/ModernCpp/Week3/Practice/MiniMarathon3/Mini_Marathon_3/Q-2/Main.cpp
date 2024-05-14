#include "Operation.h"
#include <future>

int main()
{
    OperationPointer obj;
    obj = Operation::getfirstInstances();

    Container data;
    obj->createObjects(data);

    try
    {
        std::cout << "-----------------------------------------------------" << std::endl;
        std::future<std::string> ft1 = std::async(&Operation::maxHorsePower, obj, std::ref(data));
        std::cout << "Maximum Horse Power is of: " << ft1.get() << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;

        std::future<std::optional<std::array<float, 2>>> ans = std::async(&Operation::firstLastInstances, obj, std::ref(data));
        auto var = ans.get();
        if (var.has_value())
        {
            std::cout << "Float Values are: " << (var.value())[0] << " " << (var.value())[1] << std::endl;
            std::cout << "-----------------------------------------------------" << std::endl;
        }
        else
        {
            std::cout << "No data vailable" << std::endl;
        }

        std::future<float> ft2 = std::async(&Operation::avgEngineTorque, obj, std::ref(data));
        std::cout << "Average Engine Torque is: " << ft2.get() << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;

        int n = 0;
        std::cout << "Type the value for n: ";
        std::cin >> n;
        obj->Assign(n);

        std::future<std::vector<EngineType>> ft3 = std::async(&Operation::firstNInstances, obj, std::ref(data));
        for (EngineType et : ft3.get())
        {
            if (et == EngineType::REGULAR)
            {
                std::cout << "Engine Type is: "
                          << "REGULAR" << std::endl;
                std::cout << "-----------------------------------------------------" << std::endl;
            }
            else
            {
                std::cout << "Engine Type is: "
                          << "TURBOCHARGE" << std::endl;
                std::cout << "-----------------------------------------------------" << std::endl;
            }
        }
    }
    catch (EmptyContainerException &ex)
    {
        std::future_errc::no_state;
        std::cout << ex.what() << std::endl;
    }
    catch (IdNotFoundException &ex)
    {
        std::future_errc::broken_promise;
        std::cout << ex.what() << std::endl;
    }
}
