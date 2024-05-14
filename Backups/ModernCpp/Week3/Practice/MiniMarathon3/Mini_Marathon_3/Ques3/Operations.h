#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <memory>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <condition_variable>
#include <mutex>
#include "Cab.h"
#include "EmptyContainerException.h"
#include "WrongEnumException.h"
#include "IdNotFound.h"

class Operation;

using OperationPointer = std::shared_ptr<Operation>;
using CabPointer = std::shared_ptr<Cab>;
using CabContainer = std::vector<CabPointer>;
using DriverContainer = std::vector<DriverPointer>;

class Operation
{
    static OperationPointer _solo_hero;
    Operation(){
        std::cout<<"Simple"<<std::endl;
    }
    std::mutex mt;
    std::condition_variable cv;
    bool flag = false;
    int n;
public: 
    Operation(const Operation &)=delete;
    Operation(Operation && )=delete;
    Operation & operator=(const Operation & )=delete;
    Operation &operator=(Operation &&)=delete;
    ~Operation()=default;

    static OperationPointer getInstance(){
        if(_solo_hero) return _solo_hero;
        else{
            _solo_hero.reset(new Operation());
            return _solo_hero;
        }
    }

    void CreateObject(DriverContainer& data1, CabContainer& data2);
    void PaymentMode(CabContainer& data, VType& id);
    void MinMaxFare(CabContainer& data);
    void TakeInput();
    void NInstaces(CabContainer& data);
    int NII(CabContainer& data, std::future<int>& ft);
};

#endif // OPERATIONS_H
