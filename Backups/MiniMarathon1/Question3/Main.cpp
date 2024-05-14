#include "Functionalities.h"

#include <iostream>

int main(){
    Container data;

    //Cteating the data
    CreateObject(data);

    //handling the exception
    try{
        std::cout<<"Displaying the data: \n";
        DisplayObject(data);

        std::cout<<"\n\nPrinting the service cost\n";
        PrintCalculateServicingCost(data);

        std::cout<<"\n\nPrinting the tax excemption\n";
        PrintTaxExcemption(data);

        std::cout<<"\n\nVehicle objects\n";
        PrintVehicleObject(data, "PB018882");
    }

    //Catching the exception
    catch(EmptyContainerException &ex){
        std::cout<<ex.what();
    }
}

