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
        std::optional<std::vector<int>> ans = dt->FilterData();

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
        dt->DisplaySumNonEven();

        // Displaying the result
        std::thread t3(&DataHandler::DisplayData, dt);

        // Creting a thread 1
        std::thread t1(&DataHandler::ComputerSquare, dt);
        t3.join(); 
        t1.join();

        // Crating the thread2
        std::thread t2(&DataHandler::CubeData, dt);
        t2.join();

        // Creting a thread 1
        std::thread t4(&DataHandler::ValueAtIndex, dt);

        std::thread t5(&DataHandler::ValueToN, dt);
        t5.join();
        t4.join();
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