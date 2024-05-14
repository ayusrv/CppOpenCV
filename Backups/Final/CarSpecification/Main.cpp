#include "ElectricCar.cpp"
#include "DieselCar.cpp"
#include "CarSpecification.cpp"
#include<iostream>

//Display function to display
void displayDetails(ElectricCar ec[], DieselCar dc[]){

    //Calling the Electric Car object
    for(int i=0;i<2;i++){
        std::cout<<ec[i];
    }

    //Calling the Diesel Car object
    for(int i=0;i<2;i++){
        std::cout<<dc[i];
    }
}

//Sow function display the details after type casting
void show(ElectricCar ec[], DieselCar dc[]){
    for(int i=0;i<2;i++){
        ec[i].showElectricCarDetails();
    }
    for(int i=0;i<2;i++){
        dc[i].showDieselCarDetails();
    }
}

int main(){

    //Created two stack memory
    ElectricCar ec[2];

    //Taking the input for electric car
    for(int i=0;i<2;i++){
        std::cin>>ec[i];
    }

    //Creating two DIesel car
    DieselCar dc[2];
    for(int i=0;i<2;i++){
        std::cin>>dc[i];
    }

    //Creating the car specification for pointer array
    CarSpecification *cs[4];

    //Assigning the values and typecasting to Electric class
    for(int i=0;i<2;i++){
        cs[i] = &ec[i];
    }

    //Assigning the values and typecasting to Diesel Class
    for(int i=0;i<2;i++){
        cs[2+i] = &dc[i];
    }

    //Display the data
    displayDetails(ec, dc);

    //Calling the show fnction
    show(ec,dc);
}