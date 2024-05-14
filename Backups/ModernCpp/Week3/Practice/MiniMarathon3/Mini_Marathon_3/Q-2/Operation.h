#ifndef OPERATION_H
#define OPERATION_H

#include <memory>
#include <vector>
#include <optional>
#include "Engine.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"

using EnginePointer = std::shared_ptr<Engine>;
using Container = std::vector<EnginePointer>;

class Operation;
using OperationPointer = std::shared_ptr<Operation>;

class Operation
{
private:
    int _N{0};
    static OperationPointer _solo_hero_obj;
public:
    Operation()=default;          // Default constructor enabled 
    
    Operation(const Operation&)=delete;              // Copy constructor disabled
    
    Operation(Operation&&)=delete;                   // Move Constructor disabled
    
    Operation& operator=(const Operation&)=delete;      // Copy Assignment Operator diabled
    
    Operation& operator=(Operation&&)=delete;       // Move Assignment Operator disabled
    
    ~Operation()=default;                      // Default destructor enabled

    static OperationPointer getfirstInstances(){
        if(_solo_hero_obj){
            //return address of existing object
            return _solo_hero_obj;
        }
        else{
            //no object is pre existing , need to make a new one
            _solo_hero_obj.reset(new Operation());
            return _solo_hero_obj;
        }
        
    }

    std::optional<std::array<float, 2>> firstLastInstances(Container&); 

    void Assign(int n);

    void createObjects(Container &data);
    std::string maxHorsePower(Container &data);
    float avgEngineTorque(Container &data);
    std::vector<EngineType> firstNInstances(Container &data);

    int n() const { return _N; }
    void setN(int N) { _N = N; }
};

#endif // OPERATION_H
