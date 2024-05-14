#include "Functionalities.h"

int main()
{
    Container data;
    std::future<void> create = std::async(CreateObject, std::ref(data));
    create.get();

    try{

        //Getting the NInstances
        ClassType type = ClassType::EvCar_TYPE;
        int n=1;
        std::future<void> Ninst = std::async(NInstances, std::ref(data), std::ref(type), std::ref(n));
        Ninst.get();

        //Checkng the fuel tank capacity
        std::future<bool> TankCap = std::async(TankCapacity, std::ref(data));
        std::cout<<"Fuel tank capacity is above 30 or not "<<std::boolalpha<<TankCap.get()<<std::endl;

        //Counting the ICE Cars in the variant
        std::future<void> countCars = std::async(CountICECar, std::ref(data));
        countCars.get();

        //Getting the evcars
        float f = 35;
        std::future<Container> cont = std::async(BatteryThreshold, std::ref(data), std::ref(f));
        cont.get();

        //Displaying the data
        std::future<void> dis = std::async(Display, std::ref(data));
        dis.get();

        //Displaing the nth data
        std::future<void> disp = std::async(DisplayNth, std::ref(data), std::ref(n));
        disp.get();

    }
    
    catch(EmptyContainerException& ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
    catch(SizeExceedException& ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
    catch(TypeNotFound& ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
    catch(BatteryCapacityExceed& ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
}
