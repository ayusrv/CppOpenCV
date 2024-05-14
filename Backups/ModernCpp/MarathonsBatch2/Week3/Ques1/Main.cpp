#include "DataOperation.h"

int main()
{
    std::vector<int> _data {1,2,3,4,5,6};
    UniquePointer& obj = DataOperation::getInstance(_data, 5);
    obj.get()->Display();
}