#include "Functionalities.h"
int main()
{
    Container data;
    PermitContainer data2;
    CreateObject(data, data2);
    try
    {
        Container _n_instances = NInstances(data, data2, 4);
        for (Pointer p : _n_instances)
        {
            std::cout << *p << std::endl;
        }
        std::string type;
        std::cout << "Enter the type to search like \t CAB/cab \t BUS/bus \t CAR/car\n";
        std::cin >> type;
        if(type == "CAB" || type=="cab" || type == "BUS" || type=="bus" || type == "BIKE" || type=="bike"){
            std::cout << "Average Charge per booking: " << AverageCharge(data, data2, type) << std::endl;
        }
        std::cout << "Maximum Charges: " << MaximumCharge(data, data2) << std::endl;
        Container _first_n_instances = FirstNInstances(data, data2, 3);
        for (Pointer p : _first_n_instances)
        {
            std::cout << *p << std::endl;
        }
        std::cout<<"______________________________________________________"<<std::endl;
        Adapter(NInstances, data, data2, 3);
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (SizeNotMatched &size)
    {
        std::cout << size.what() << std::endl;
    }
    catch (NullPointerException &np)
    {
        std::cout<<np.what()<<std::endl;
    }
}