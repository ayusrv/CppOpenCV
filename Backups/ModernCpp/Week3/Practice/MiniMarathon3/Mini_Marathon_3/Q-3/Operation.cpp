#include "Operation.h"

OperationPointer Operation::_solo_hero_obj{nullptr};

void Operation::createObjects(CabContainer &data, DriverContainer& data2){
        data2.push_back(std::make_shared<Driver>("AB12", DriverRating::STAR_1));
        data2.push_back(std::make_shared<Driver>("CD45", DriverRating::STAR_2));
        data2.push_back(std::make_shared<Driver>("EF98", DriverRating::STAR_3));
        data2.push_back(std::make_shared<Driver>("gh12", DriverRating::STAR_2));
        data2.push_back(std::make_shared<Driver>("kl12", DriverRating::STAR_1));

        data.push_back(std::make_shared<CabRide>("1", RideType::LOCAL, PaymentMode::CARD, 100.0f, "Pune", "Mumbai", std::ref(data2[0])));
        data.push_back(std::make_shared<CabRide>(2, RideType::OUTSTATION, PaymentMode::UPI, 120.0f, "Alwar", "Mumbai", std::ref(data2[1])));
        data.push_back(std::make_shared<CabRide>(3, RideType::LOCAL, PaymentMode::WALLET, 150.0f, "Pune", "Goa", std::ref(data2[2])));
        data.push_back(std::make_shared<CabRide>("4", RideType::OUTSTATION, PaymentMode::CASH, 90.0f, "Jaipur", "Mumbai", std::ref(data2[3])));
        data.push_back(std::make_shared<CabRide>(5, RideType::LOCAL, PaymentMode::CARD, 50.0f, "Goa", "Mumbai", std::ref(data2[4])));
}

void Operation::paymentMode(CabContainer &data){
        if(data.empty()){
            throw EmptyContainerException("Data Not Found!");
        }
        std::variant<int, std::string> temp;
        temp=2;
        for(CabPointer c:data){
            if(temp==c->id()){
                if(c->pMode()==PaymentMode::UPI){
                    std::cout<<"Payment Mode is: "<<"UPI"<<std::endl;
                }
                else if(c->pMode()==PaymentMode::WALLET){
                    std::cout<<"Payment Mode is: "<<"WALLET"<<std::endl;
                }
                else{
                    std::cout<<"Payment Mode is: "<<"Others"<<std::endl;
                }
            }
        }
    }

    void Operation::MinMaxFare(CabContainer &data){
        if(data.empty()){
            throw EmptyContainerException("Data Not Found!");
        }
        float min=data[0]->fare();
        float max=data[0]->fare();
        std::array<float, 2> ans;
        for(CabPointer c:data){
            if(min>c->fare()){
                min=c->fare();
            }
            if(max<c->fare()){
                max=c->fare();
            }
        }
        ans[0]=min;
        ans[1]=max;
        std::cout<<"Min and Max are: ";
        for(float i:ans){
            std::cout<<i<<" ";
        }
        std::cout<<""<<std::endl;
    }

    void Operation::pickupLocation(CabContainer &data, int n){
        if(data.empty()){
            throw EmptyContainerException("Data Not Found!");
        }
        std::cout<<"Pickup Locations are: ";
        for(CabPointer c:data){
            if(n==0){
                return;
            }
            std::cout<<c->pickupLocation()<<" ";
            n--;
        }
        std::cout<<""<<std::endl;
    }

    void Operation::createDriver(CabContainer &data, int n){
        if(data.empty()){
            throw EmptyContainerException("Data Not Found!");
        }
        DriverContainer temp;
        std::cout<<""<<std::endl;
        std::cout<<"Driver Instances Copied Id's are: ";
        for(int i=data.size()-1; i>=0; i--){
            if(n==0){
                return;
            }
            std::cout<<((data[i]->cabDriver()).get())->driverId()<<" ";
            temp.push_back((data[i]->cabDriver()).get());
            n--;
        }
        std::cout<<""<<std::endl;
    }