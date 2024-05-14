#include "Functionalities.h"
#include <mutex>
std::mutex mt;

FType CreateObject = [](Container &data)
{
    data.push_back(std::make_shared<DataModel>(std::make_shared<BussinessOwner>(500, 1000, "ABC", BussinessType::MNC), std::vector<float>{10, 20, 30, 40, 50}));

    data.push_back(std::make_shared<DataModel>(std::make_shared<Employee>("Ayush", 30000, EmployeeType::REGULAR), std::vector<float>{50, 60, 70, 80, 90}));

    data.push_back(std::make_shared<DataModel>(std::make_shared<BussinessOwner>(300, 2000, "XYZ", BussinessType::SME), std::vector<float>{15, 25, 35, 45, 55}));

    data.push_back(std::make_shared<DataModel>(std::make_shared<Employee>("Rahul", 50000, EmployeeType::OVERSEAS), std::vector<float>{10, 20, 30, 40, 50}));
};

FType CalculateTaxPayable = [](Container &data)
{
    std::lock_guard<std::mutex> lg(mt);
    for (DataPointer dp : data)
    {
        const VType &v = dp->instances();
        if (std::holds_alternative<BussinessPointer>(v))
        {
            BussinessPointer b = std::get<0>(v);
            std::cout << "Total tax to pay: " << (0.1) * (b->revenue() - b->expenses()) << std::endl;
        }
        else
        {
            if (EmployeePointer e = std::get<1>(v); e->employeeType() == EmployeeType::REGULAR)
            {
                // std::lock_guard<std::mutex> lg(mt);
                std::cout << "Payable Tax is: " << 0.1f * e->salary() << std::endl;
            }
            else
            {
                // std::lock_guard<std::mutex> lg(mt);
                std::cout << "Payable tax is: " << 0.2f * e->salary() << std::endl;
            }
        }
    }
};

FType CallParentOperator = [](Container &data)
{
    std::lock_guard<std::mutex> lg(mt);
    for (DataPointer d : data)
    {
        d->operator()();
    }
};

std::function<int(Container &, std::future<int> &ft)> GetData = [](Container &, std::future<int> &ft)
{
    int *ptr = (int *)malloc(4);
    *ptr = ft.get();
    return *ptr;
};