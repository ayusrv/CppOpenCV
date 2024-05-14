#include "Functionalities.h"

void CreateObject(Container &data)
{
    data.push_back(std::make_shared<OnlinePayment>("Hello9","Phase1","Phase3",117.6,PaymentType::CARD, 2));
    data.push_back(std::make_shared<CashPayment>("Hello9","Phase1","Phase3",117.6, 20));
    data.push_back(std::make_shared<OnlinePayment>("Hello9","Phase1","Phase3",117.6,PaymentType::ONLINE_WALLET, 2));
    data.push_back(std::make_shared<CashPayment>("Hello9","Phase1","Phase3",117.6,30));
}

void DisplayObject(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not assigned");
    }
    for(CabBook c : data){
        if(typeid(*c) == typeid(OnlinePayment)){
            std::shared_ptr<OnlinePayment> op = std::dynamic_pointer_cast<OnlinePayment>(c);
            std::cout<<*op<<std::endl;
        }
        else if(typeid(*c) == typeid(CashPayment)){
            std::shared_ptr<CashPayment> op = std::dynamic_pointer_cast<CashPayment>(c);
            std::cout<<*op<<std::endl;
        }
    }
}

std::string FindMaxBookingID(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not assigned");
    }
    CabBook maxCab = data[0];
    for(CabBook cb : data){
        if(maxCab->CabFareCalculation() < cb->CabFareCalculation()){
            maxCab = cb;
        }
    }
    return maxCab->bookingId();

}

Container NInstance(Container &data, int n)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not assigned");
    }
    if(n<=0 || n>data.size()){
        throw std::runtime_error("Instances doesn't match");
    }
    Container Instances;
    for(int i = data.size()-1; i>data.size()-n;i--){
        Instances.push_back(data[i]);
    }
    return Instances;
}

bool Above1000(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not assigned");
    }
    for(CabBook cb : data){
        if(cb->CabFareCalculation()<1000){
            return false;
        }
    }   
    return true;
}
