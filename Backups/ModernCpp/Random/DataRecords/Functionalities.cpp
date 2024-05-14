#include "Functionalities.h"

void createObject(Container &data, UnitContainer &data2)
{
    std::vector<int> provided_values1{1, 2, 3, 4, 5};
    std::vector<int> provided_values2{7, 8, 9, 10, 11};
    std::vector<int> provided_values3{3, 4, 5, 6, 7};
    std::vector<int> provided_values4{13, 14, 15, 16, 17};
    std::vector<int> provided_values5{23, 24, 25, 26, 27};

    std::vector<int> expected_values1{6, 7, 8, 9, 10};
    std::vector<int> expected_values2{2, 3, 4, 5, 6};
    std::vector<int> expected_values3{8, 9, 10, 11, 12};
    std::vector<int> expected_values4{22, 23, 24, 25, 26};
    std::vector<int> expected_values5{12, 13, 14, 15, 16};

    data2.push_back(std::make_shared<DataUnit>(12, UnityType::IN_HOUSE, 20.5));
    data2.push_back(std::make_shared<DataUnit>(13, UnityType::OUTSOURCED, 22.5));
    data2.push_back(std::make_shared<DataUnit>(14, UnityType::OUTSOURCED, 24.5));

    data.push_back(std::make_shared<DataRecord>(provided_values1, expected_values1, std::ref(data2[0])));
    data.push_back(std::make_shared<DataRecord>(provided_values2, expected_values2, std::ref(data2[1])));
    data.push_back(std::make_shared<DataRecord>(provided_values3, expected_values3, std::ref(data2[2])));
    data.push_back(std::make_shared<DataRecord>(provided_values4, expected_values4, std::ref(data2[1])));
    data.push_back(std::make_shared<DataRecord>(provided_values5, expected_values5, std::ref(data2[0])));
}

FType PrintCertainData = [](Container &data)
{
    for (DataRecordPointer dr : data)
    {
        int sum1 = 0, sum2 = 0;
        std::vector<int> temp= dr->dataValuesProvided();
        std::vector<int> temp2= dr->dataValuesExprected();
        sum1 = std::accumulate(
            temp.begin(),
            temp.end(),
            sum1
        );

        sum2 = std::accumulate(
            temp2.begin(),
            temp2.end(),
            sum2);

        if(sum1>sum2)
        {
            std::cout<<"Printing the data whose sum of provided values is more than the expected values\n";
            std::cout<<*dr<<std::endl;
        }

        if (dr->dataUnit().get()->unitId() > 10)
        {
            std::cout << "Data unit is more than 10\n";
            std::cout << *dr << std::endl;
        }
    }
};

FType PrintMaximum = [](Container &data)
{
    auto itr = std::max_element(
        data.begin(),
        data.end(),
        [](DataRecordPointer v1, DataRecordPointer v2)
        {
            return v1.get()->dataUnit().get()->unitId() < v2.get()->dataUnit().get()->unitId();
        });

    std::cout << "Maximum values : " << *(*itr) << std::endl;
};

FType getOdd = [](Container &data)
{
    std::cout << "\n\n\nPrnting the odd objects\n";
    int i = 1;
    for (DataRecordPointer dp : data)
    {
        if (i % 2 == 1)
        {
            std::cout << *dp;
        }
        i++;
    }
};

void HighOrder(Container &data, FType &fn)
{
    fn(data);
}