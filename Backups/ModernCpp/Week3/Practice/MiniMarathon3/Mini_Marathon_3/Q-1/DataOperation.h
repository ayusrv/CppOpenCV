#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <memory>
#include <vector>

class DataOperation;

using OperationPointer = std::shared_ptr<DataOperation>;

class DataOperation
{
private:
    std::vector<int> _dataVector{10,21,30,41,50};
    unsigned int _magicNumber;
    static OperationPointer _solo_hero_obj;
    DataOperation(unsigned int magicNumber)
    :_magicNumber{magicNumber}{}

public:
    DataOperation()=default;          // Default constructor enabled 
    
    DataOperation(const DataOperation&)=delete;              // Copy constructor disabled
    
    DataOperation(DataOperation&&)=delete;                   // Move Constructor disabled
    
    DataOperation& operator=(const DataOperation&)=delete;      // Copy Assignment Operator diabled
    
    DataOperation& operator=(DataOperation&&)=delete;       // Move Assignment Operator disabled
    
    ~DataOperation()=default;                      // Default destructor enabled

    static OperationPointer getfirstInstances(unsigned int magicNumber){
        if(_solo_hero_obj){
            return _solo_hero_obj;
        }
        else{
            //no object is pre existing , need to make a new one
            _solo_hero_obj.reset(new DataOperation(magicNumber));
            return _solo_hero_obj;
        }
        
    }

    std::vector<int> dataVector() const { return _dataVector; }
    void setDataVector(const std::vector<int> &dataVector) { _dataVector = dataVector; }

    unsigned int magicNumber() const { return _magicNumber; }
    void setMagicNumber(unsigned int magicNumber) { _magicNumber = magicNumber; }
};


#endif // OPERATION_H
