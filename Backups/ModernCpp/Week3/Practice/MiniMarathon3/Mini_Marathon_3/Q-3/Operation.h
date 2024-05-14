#ifndef OPERATION_H
#define OPERATION_H

#include "CabRide.h"
#include "EmptyContainerException.h"
#include <vector>

class Operation;

using CabPointer = std::shared_ptr<CabRide>;

using CabContainer = std::vector<CabPointer>;

using DriverContainer = std::vector<DriverPointer>;

using OperationPointer = std::shared_ptr<Operation>;

class Operation
{
private:
    static OperationPointer _solo_hero_obj;
    Operation(int amount){}
public:
    Operation()=default;          // Default constructor enabled 
    
    Operation(const Operation&)=delete;              // Copy constructor disabled
    
    Operation(Operation&&)=delete;                   // Move Constructor disabled
    
    Operation& operator=(const Operation&)=delete;      // Copy Assignment Operator diabled
    
    Operation& operator=(Operation&&)=delete;       // Move Assignment Operator disabled
    
    ~Operation()=default;                      // Default destructor enabled

    static OperationPointer getfirstInstances(int amount){
        if(_solo_hero_obj){
            //return address of existing object
            return _solo_hero_obj;
        }
        else{
            _solo_hero_obj.reset(new Operation(amount));
            return _solo_hero_obj;
        }
    }   
    void createObjects(CabContainer &data, DriverContainer& data2);

    void paymentMode(CabContainer &data);

    void MinMaxFare(CabContainer &data);

    void pickupLocation(CabContainer &data, int n);

    void createDriver(CabContainer &data, int n);
};





#endif // OPERATION_H
