#include "Functionalities.h"

int main()
{
    Container data;
    CreateObject(data);
    std::cout<<CountTransactionOfGivenType(data, TransactionType::UPI)<<"\n";
    std::cout<<TotalTransactionAmount(data)<<"\n";
    std::cout<<FindMaxAccountBalance(data, TransactionType::CARD)<<"\n";
    std::optional<Container> res = AccountAboveThreshold(data,100);
    if(res.has_value()){
        for(auto d : res.value()){
            std::cout<<*d<<"\n";
        }
    }
    else{
        std::cout<<"Main nhi aau ga\n";
    }
    std::cout<<NthTransactionId(data,2)<<"\n";
    std::cout<<AverageTransactionAmount(data)<<"\n";
    std::cout<<"Printing the tax \n";
    std::future<void> fut = std::async(BalanceInterest, std::ref(data));
    fut.get();
}