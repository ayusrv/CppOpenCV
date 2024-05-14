#include "DataHandler.h"

int main()
{
    try
    { // Contaier or data
        Container data{1, 2, 3, 4, 5};
        // Container of results
        Container result;
        // Making an object
        OperationPointer dt = DataHandler::getFirstInstance(data, result);

        // Calling the filtered data
        std::optional<std::vector<int>> ans = dt->FilterData(data);

        // Checking if it has value or not
        if (ans.has_value())
        {
            std::cout << "Printing the value of the Filtered data: ";
            for (int i : ans.value())
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "NO data has filtered out\n";
        }

        // Calling the sum non even
        dt->DisplaySumNonEven(data);

        // Creting a thread 1
        std::thread t1(&DataHandler::ComputerSquare, dt, std::ref(data));
        t1.join();

        // Displaying the result
        dt->DisplayData();

        // Crating the thread2
        std::thread t2(&DataHandler::CubeData, dt, std::ref(data));
        t2.join();
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(NoOddFound &ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
}