#include "ParkingBill.cpp"
#include "Vehicle.cpp"
#include<iostream>
// #include<bits/stdc++.h>

//User Defined exception handling
class temp: public std::exception{
    public:
        const char* what(){
            return "Vehicle Not Found!!";
        }
};

int main(){

    //Setting size
    int size=2;

    //creating the array
    Parking_Bill pb[size];

    //Taking the input
    for(int i=0;i<size;i++){
        std::cin>>pb[i];
    }

    //Printing the output
    std::cout<<std::endl<<std::endl;
    for(int i=0;i<size;i++){
        std::cout<<pb[i];
    }

    //Printing the total Vehicle
    std::cout<<"Totol Vehicle: "<<Vehicle::totalVehicle<<std::endl;

    //Printing the total Bill
    std::cout<<"Total Bill: "<<Parking_Bill::totalBill<<std::endl;

    //Initializing the flag to store the values
    int flag=-1;

    //Creating the vechNum to store the vehicle number
    char* vechNum = new char[20];
    std::cout<<"Enter the vehicle number you want to search: ";
    std::cin>>vechNum;

    //Checking the vehicle in the parked vehicle
    for(int i=0;i<size;i++){
        if(strcmp(vechNum,pb[i].parkedVehicle().getVehicleNum())){
            flag=i;
        }
    }

    //Try catch to check if details not available
    try{
        if(flag==-1){
            temp e;
            throw e;
        }
        std::cout<<std::endl<<std::endl<<"Details of your Vehicle Number: "<<std::endl;
        std::cout<<pb[flag];
    }
    catch(temp e){
        std::cout<<e.what()<<std::endl;
    }

    //Printing the details for 2 wheeler and 4 wheeler
    std::cout<<std::endl<<std::endl<<"Details for Parking Bill: "<<std::endl;
    pb[0].setParkingCharges2wheelers();
    pb[0].setParkingCharges4wheelers();
}