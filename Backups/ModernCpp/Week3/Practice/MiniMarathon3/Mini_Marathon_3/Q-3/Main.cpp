#include "Operation.h"

int main(){
    CabContainer data;
    DriverContainer data2;

    OperationPointer obj=Operation::getfirstInstances(1000);

    obj->createObjects(data, data2);

    try{
        obj->paymentMode(data);
        obj->MinMaxFare(data);
        obj->pickupLocation(data, 2);
        obj->createDriver(data, 3);
        std::cout<<std::endl;
    }
    catch(EmptyContainerException& ex){
        std::cout<<ex.what()<<std::endl;
    }
}