#include "Functionalities.h"
#include <iostream>

int main(){
    Container data;

    //Creating a data
    CreateObject(data);

    try{
        //Displaying the data
        DisplayObject(data);
        
        //Getting the average milage of all the inputs
        std::cout<<"Mileage of all data: "<<AverageMilage(data)<<std::endl;

        //Prints number of instances that Priavte data have
        std::cout<<"Number of INstances matches the data: "<<NumberInstances(data, "PRIVATE")<<std::endl;

        //Checking if the price is above 20000 or not
        std::cout<<"Price is above 20000 or not "<<PriceAbove20000(data)<<std::endl;
    }
    catch(EmptyContainerException &ex){
        std::cout<<ex.what();
    }
}