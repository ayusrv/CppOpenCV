#include <iostream>
#include "Functionalities.h"

#define line(msg) std::cout<<"__________________"#msg"_______________"
int main(){
    Container data;
    CreateObject(data); 
    line(Cab);
    try{
        DisplayObject(data);
        std::cout<<FindMaxBookingID(data)<<std::endl;
        std::cout<<Above1000(data)<<std::endl;
        Container Instances = NInstance(data,3);
        for(CabBook c : Instances){
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
    catch(EmptyContainerException &e){
        std::cout<<e.what();
    }
}