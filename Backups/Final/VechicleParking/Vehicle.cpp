#include "Vehicle.h"
#include <iostream>
#include<string>
#include<cstring>

//Staic in total vehicle
int Vehicle::totalVehicle=0;

//Default Constructor
Vehicle::Vehicle(){
    vehicleNum = nullptr;
    vehicle_type = TWOWH;
    parking_hrs = 0;
    parking_id = 0;
}

//Getter Setter for vehicle number
char* Vehicle::getVehicleNum(){ return vehicleNum; }
void Vehicle::setVehicleNum(char* vehicleNum_) { vehicleNum = vehicleNum_; }

//Getter Setter for the Vehicle Types
types Vehicle::getVehicleType(){ return vehicle_type; }
void Vehicle::setVehicleType(const types &vehicleType) { vehicle_type = vehicleType; }

//Getter Setter for parking hours
int Vehicle::getParkingHrs() { return parking_hrs; }
void Vehicle::setParkingHrs(int parkingHrs) { parking_hrs = parkingHrs; }

//Getter setter for PakringId
int Vehicle::getParkingId() { return parking_id; }
void Vehicle::setParkingId(int parkingId) { parking_id = parkingId; }
        
//Taking input for the Vehicle
std::istream & operator>>(std::istream& in, Vehicle &v){

    //Static increasing the total vehicle
    Vehicle::totalVehicle++;
    std::cout<<"Enter the Vehicle Number: ";

    //taking vehicle number in input
    char *vechNo = new char[10];
    in>>vechNo;
    v.vehicleNum = vechNo;

    //Creating vehicle check to make sure the type of vehicle
    vehicleCheck:
    std::cout<<"Enter Vehicle Type 1 for TWOWH and 2 for FOURWH: ";
    int x;
    std::cin>>x;
    if(x==0){
        v.vehicle_type=TWOWH;
    }else if(x==1){
        v.vehicle_type=FOURWH;
    }
    else{
        std::cout<<"Please enter the correct type: ";
        //goto the statement if the codition does not meet
        goto vehicleCheck;
    }
    std::cout<<"Enter Parking Hours: ";
    in>>v.parking_hrs;

    std::cout<<"Enter Parking ID: ";
    in>>v.parking_id;
    return in;
}

//Printing the output for the Vehicle
std::ostream & operator<<(std::ostream& out, Vehicle &v){
    out<<"Vehicle Number: "<<v.vehicleNum<<std::endl;
    out<<"Vehicle Type: ";
    if(v.vehicle_type==TWOWH){
        out<<"TWOWH"<<std::endl;
    }else{
        out<<"FOURWH"<<std::endl;
    }
    out<<"Parking Hours: "<<v.parking_hrs<<std::endl;
    out<<"Parking ID: "<<v.parking_id<<std::endl;
    return out;
}

//Shwoing the total number of vehicles
void Vehicle::showVehicle(){std::cout<<"Totale Vehicle: "<<totalVehicle<<"\n";}