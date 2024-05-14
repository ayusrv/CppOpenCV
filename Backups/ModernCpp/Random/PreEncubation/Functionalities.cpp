#include "Functionalities.h"
std::mutex mt;
std::function<void(Container &)> CreateObject = [](Container &data)
{
    TransactionPointer t1 = std::make_shared<Transaction>("123", 10000, TransactionType::CARD);
    TransactionPointer t2 = std::make_shared<Transaction>("122", 12000, TransactionType::CASH);
    TransactionPointer t3 = std::make_shared<Transaction>("133", 13000, TransactionType::CASH);
    TransactionPointer t4 = std::make_shared<Transaction>("144", 14000, TransactionType::UPI);
    TransactionPointer t5 = std::make_shared<Transaction>("155", 15000, TransactionType::UPI);
    TransactionPointer t6 = std::make_shared<Transaction>("166", 16000, TransactionType::CARD);
    TransactionPointer t7 = std::make_shared<Transaction>("177", 17000, TransactionType::CARD);

    TransactionConatiner tc1{t1, t2, t3};
    TransactionConatiner tc2{t4, t5};
    TransactionConatiner tc3{t6, t7};

    data.push_back(std::make_shared<Account>("1234", tc1, 12000));
    data.push_back(std::make_shared<Account>("1235", tc2, 14000));
    data.push_back(std::make_shared<Account>("1236", tc3, 9000));
};

std::function<int(Container &, TransactionType)> CountTransactionOfGivenType = [](Container &data, TransactionType TType)
{
    int count = 0;
    for (AccountPointer ap : data)
    {
        TransactionConatiner tc = ap->transactionSet();
        int c = std::count_if(
            tc.begin(),
            tc.end(),
            [&](TransactionPointer &tp)
            {
                return tp->transactionType() == TType;
            });
        count += c;
    }
    return count;
};

std::function<float(Container &)> TotalTransactionAmount = [](Container &data)
{
    float totalAmount = 0;
    totalAmount = std::accumulate(
        data.begin(),
        data.end(),
        0,
        [](int startData, AccountPointer &ap)
        {
            return startData + ap->accountBalance();
        });
    return totalAmount;
};

std::function<float(Container &, TransactionType)> FindMaxAccountBalance = [](Container &data, TransactionType TType)
{
    auto itr = std::max_element(
        data.begin(),
        data.end(),
        [&](AccountPointer &ap1, AccountPointer &ap2)
        {
            return ap1->accountBalance() < ap2->accountBalance();
        });
    return itr->get()->accountBalance();
};

std::function<std::optional<Container>(Container &, float)> AccountAboveThreshold =
    [](Container &data, float n) -> std::optional<Container>
{
    std::vector<AccountPointer> res(data.size());
    auto itr = std::copy_if(
        data.begin(),
        data.end(),
        res.begin(),
        [&](AccountPointer &ap)
        {
            return ap->accountBalance() > n;
        });
    res.resize(std::distance(res.begin(), itr));
    if (res.empty())
    {
        return std::nullopt;
    }
    return res;
};

std::function<std::string(Container &, int)> NthTransactionId = [](Container &data, int N)
{
    if (N > 0 && N <= data.size())
    {
        return data[N - 1]->accountId();
    }
    std::string s = "Size exceed";
    return s;
};

std::function<float(Container &)> AverageTransactionAmount = [](Container &data)
{
    int count = 0;
    float tot = 0;
    for (AccountPointer ap : data)
    {
        TransactionConatiner tc = ap->transactionSet();
        float c = std::accumulate(
            tc.begin(),
            tc.end(),
            0.0f,
            [&](float sum1, TransactionPointer &tp)
            {
                return sum1 + tp->transactionAmount();
            });
        tot += c;
        count += tc.size();
    }
    return tot / count;
};

float calculateTax(AccountPointer ap)
{
    std::lock_guard<std::mutex> lg(mt);
    int ineterst;
    if (ap->accountBalance() < 10000)
    {
        ineterst = 0;
    }
    else
    {
        ineterst = ap->accountBalance() * 0.04;
    }
    return ineterst;
}

std::function<void(Container &)> BalanceInterest = [](Container &data)
{
    float interest = 0;
    for (AccountPointer ap : data)
    {
        std::future<float> getInt = std::async(calculateTax, ap);
        interest = getInt.get();
        std::cout << "Total amoyunt with interest: " << ap->accountBalance() + interest << '\n';
    }
};