#include "DataOperation.h"

UniquePointer DataOperation::_object = nullptr;

DataOperation::DataOperation(std::vector<int> data, unsigned int magic_numer) : _data{data}, _magic_numer{magic_numer} {}

UniquePointer &DataOperation::getInstance(std::vector<int> data, unsigned int magic_number)
{
    if (!_object)
    {
        _object = std::unique_ptr<DataOperation>(new DataOperation(data, magic_number));
    }
    return _object;
}

void DataOperation::Display()
{
    for (int i : _data)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
