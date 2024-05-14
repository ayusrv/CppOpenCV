#include "DataHandler.h"

//Initilaizing the solo hero
OperationPointer DataHandler::_solo_hero{nullptr};

//Filtered data has been called
std::optional<std::vector<int>> DataHandler::FilterData(Container &data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    std::vector<int> res;
    for (int i : data)
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
void DataHandler::DisplaySumNonEven(Container &data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    int sum = 0;
    for (int i : data)
    {
        if (sum % 2 != 0)
            sum += i;
    }
    if(sum==0)
    {
        throw NoOddFound("No odd data found");
    }
    std::cout << "Sum of all non even numbers are: " << sum << "\n";
}

//Setting the value in the data and then calling the Condition variable to get the result
void DataHandler::ComputerSquare(Container &data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }

    //Appliying the lock_gaurd
    std::lock_guard<std::mutex> lg(mt);

    //Storing the data in the result
    Container res;
    for (int i = 0; i < data.size(); i++)
    {
        res[i] = data[i] * data[i];
    }
    //calling the setter
    setResult(res);
    flag = true;

    //Notifying the CV
    cv.notify_one();
}

//Displing the data of the result
void DataHandler::DisplayData()
{
    //Applying he unique lock
    std::unique_lock<std::mutex> ul(mt);

    std::cout << "Display of result function has been called" << std::endl;

    //Cheking the condition
    cv.wait(ul, [&]()
            { return flag; });
    std::cout << "Results are: ";

    //Printing the results
    for (int i : result())
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

//Printing the cube of the data
void DataHandler::CubeData(Container &data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }

    std::lock_guard<std::mutex> lg(mt);
    std::cout << "Printing the Cube of the data that has been passed: ";
    for (int i : data)
    {
        std::cout << i*i*i << " ";
    }
    std::cout << std::endl;
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
