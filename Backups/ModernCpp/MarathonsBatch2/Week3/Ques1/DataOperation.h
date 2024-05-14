#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include <iostream>
#include <vector>
#include <memory>

class DataOperation;
using UniquePointer = std::unique_ptr<DataOperation>;
using SharedPointer = std::shared_ptr<DataOperation>;

class DataOperation
{
private:
    std::vector<int> _data;
    unsigned int _magic_numer;
    static UniquePointer _object;
    DataOperation() = default;
    DataOperation(const DataOperation&) = delete;
    DataOperation(DataOperation&&) = delete;
    DataOperation & operator=(const DataOperation&)=default;
    DataOperation & operator=(DataOperation&&)=default;
    DataOperation(std::vector<int> data, unsigned int magic_numer);
public:
    static UniquePointer& getInstance(std::vector<int> data, unsigned int magic_number);
    void Display();
    ~DataOperation()=default;
};

#endif // DATAOPERATION_H
