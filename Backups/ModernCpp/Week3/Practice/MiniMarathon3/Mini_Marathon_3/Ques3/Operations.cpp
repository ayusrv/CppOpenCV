#include "Operations.h"

OperationPointer Operation::_solo_hero{nullptr};

void Operation::CreateObject(DriverContainer& data1, CabContainer& data2)
{
    data1.push_back(std::make_shared<Driver>("120H", DriverRating::STAR_1));
    data1.push_back(std::make_shared<Driver>("130H", DriverRating::STAR_2));
    data1.push_back(std::make_shared<Driver>("140H", DriverRating::STAR_3));

    data2.push_back(std::make_shared<Cab>("1", RideType::LOCAL, PaymentMode::CARD, 300.5f, "Phase1", "Phase3", std::ref(data1[0])));

    data2.push_back(std::make_shared<Cab>("2", RideType::RENT, PaymentMode::CASH, 400.5f, "Phase3", "Phase1", std::ref(data1[1])));

    data2.push_back(std::make_shared<Cab>(3, RideType::OUTSTATION, PaymentMode::UPI, 400.5f, "Phase2", "Phase3", std::ref(data1[2])));
}

void Operation::PaymentMode(CabContainer &data, VType &idd)
{
    if(data.empty()) std::cout<<"Khali hai\n";
    for (auto cp : data)
    {
        if (std::holds_alternative<int>(cp->id()))
        {
            std::lock_guard<std::mutex> lg(mt);
            std::cout << "Total fare is: " << cp->fare() * 1.5<<'\n';
        }
        else
        {
            std::lock_guard<std::mutex> lg(mt);
            std::cout << "Total fare is: " << cp->fare() * 2<<'\n';
        }
    }
}

void Operation::MinMaxFare(CabContainer &data)
{
    std::lock_guard<std::mutex> lg(mt);
    std::array<float, 2> ans;
    auto mini = std::min_element(
        data.begin(),
        data.end(),
        [](const CabPointer &c1, const CabPointer &c2)
        {
            return c1->fare() < c2->fare();
        });
    ans[0] = (*mini)->fare();
    auto maxi = std::max_element(
        data.begin(),
        data.end(),
        [](const CabPointer &c1, const CabPointer &c2)
        {
            return c1->fare() < c2->fare();
        });
    ans[1] = (*maxi)->fare();
    std::cout << "Minimum value is : " << ans[0]<<std::endl <<"Maximum value is: " << ans[1] << std::endl;
}

void Operation::TakeInput()
{
    std::lock_guard<std::mutex> lg(mt);
    std::cout << "Enter the value of N: ";
    std::cin >> n;
    flag = true;
    cv.notify_one();
}

void Operation::NInstaces(CabContainer &data)
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&]()
            { return flag; });
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::no_state, "Empty container exception");
    }
    if (n <= 0 || n > data.size())
    {
        throw EmptyContainerException(std::future_errc::no_state, "Overloaded");
    }
    std::vector<DriverPointer> ans;
    for (int i = data.size() - 1; i >= data.size()-n; --i)
    {
        if(data[i])
            ans.push_back(data[i]->cabDriver());
        else   
            break;
    }
    for (DriverPointer dp : ans)
    {
        std::cout << *dp << std::endl;
    }
}

int Operation::NII(CabContainer& data, std::future<int>& n)
{
    int val = n.get();
    return val*10;
}