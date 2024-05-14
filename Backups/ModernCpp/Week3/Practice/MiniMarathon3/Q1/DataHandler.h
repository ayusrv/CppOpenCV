#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <array>
#include <iostream>
#include <vector>
#include <optional>
#include <memory>
#include <future>
#include <functional>
#include <thread>
#include <condition_variable>
#include "EmptyContainerException.h"
#include "NoOddFound.h"

using Container = std::array<int, 5>;

class DataHandler;
using OperationPointer = std::shared_ptr<DataHandler>;

class DataHandler
{

private:
    bool flag = false;
    std::mutex mt;
    std::condition_variable cv;

    Container _data;
    int val{0};
    Container _result;
    DataHandler(Container data, Container result) : _data{data}, _result{result} {}
    static OperationPointer _solo_hero;

public:
    DataHandler() = delete;
    DataHandler(const DataHandler &) = delete;
    DataHandler &operator=(const DataHandler &) = delete;
    DataHandler(DataHandler &&) = delete;
    DataHandler &operator=(DataHandler &&) = delete;
    ~DataHandler() = default;

    //GetFirstInstacne function has been called
    static OperationPointer getFirstInstance(Container &data, Container &result)
    {
        if (_solo_hero)
        {
            return _solo_hero;
        }
        else
        {
            _solo_hero.reset(new DataHandler(data, result));
            return _solo_hero;
        }
    }

    // Getting the filtered data and checking the optional
    std::optional<std::vector<int>> FilterData(Container &data);
    //Checking the logic
    std::function<bool(int)> getData = [](int i)
    {
        return i % 4 == 0;
    };

    // Displaying the sum of non even numbers that has been passed
    void DisplaySumNonEven(Container &data);

    // Overloading the output operator
    friend std::ostream &operator<<(std::ostream &os, const DataHandler &rhs);

    // Setting the value of square and passing it to the diplay data
    void ComputerSquare(Container &data);

    //Displaying the result
    void DisplayData();

    //printing the cube of the data that has been passed
    void CubeData(Container &data);

    //Getter setter for data
    Container data() const { return _data; }
    void setData(const Container &data) { _data = data; }

    //Getter setter for result
    Container result() const { return _result; }
    void setResult(const Container &result) { _result = result; }
};

#endif // DATAHANDLER_H
