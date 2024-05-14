#include "DataHandler.h"

//Initilaizing the solo hero
OperationPointer DataHandler::_solo_hero{nullptr};

//Filtered data has been called
std::optional<std::vector<int>> DataHandler::FilterData()
{
    if(_data.empty())
    {
        throw EmptyContainerException("_data is empty");
    }
    std::vector<int> res;
    for (int i : _data)
    {
        bool f = getData(i);
        if (f)
        {
            res.push_back(i);
        }
    }

    if (res.empty())
    {
        return std::nullopt;
    }
    return res;
}

// Displing the sum of add number 
void DataHandler::DisplaySumNonEven()
{
    if(_data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    std::lock_guard<std::mutex> lg(mt);
    int sum = 0;
    for (int i : _data)
    {
        if (i % 2 != 0)
            sum += i;
    }
    if(sum==0)
    {
        throw NoOddFound("No odd data found");
    }
    std::cout << "Sum of all non even numbers are: " << sum << "\n";
}

//Setting the value in the data and then calling the Condition variable to get the result
void DataHandler::ComputerSquare()
{
    if(_data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    std::lock_guard<std::mutex> lg(mt);
    for(int i=0; i<_data.size();i++)
    {
        _result[i] = _data[i]*_data[i];
    }
    flag = true;
    cv.notify_one();
}

//Displing the data of the result
void DataHandler::DisplayData()
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&](){return flag;});
    std::cout<<"Displaying the data: ";
    flag = false;
    for(int i : _result)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

//Printing the cube of the data
void DataHandler::CubeData()
{
    if(_data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }

    std::lock_guard<std::mutex> lg(mt);
    std::cout << "Printing the Cube of the data that has been passed: ";
    for (int i : _data)
    {
        std::cout << i*i*i << " ";
    }
    std::cout << std::endl;
}

void DataHandler::ValueAtIndex()
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&](){return flag;});
    std::cout<<_result[N-1];
}

void DataHandler::ValueToN()
{
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"Enter value: ";
    std::cin>>N;
    flag=true;
    cv.notify_all();
}

//Output operator overloaded
std::ostream &operator<<(std::ostream &os, const DataHandler &rhs)
{
    os << "Data details: ";
    for (int i : rhs._data)
    {
        os << i << " ";
    }
    os << std::endl
       << "Result details: ";
    for (int i : rhs._result)
    {
        os << i << " ";
    }
    os << std::endl;
    return os;
}
