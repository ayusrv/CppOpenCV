#include "ParkingBill.h"
#include <iostream>

//Initializing the Bill No
int Parking_Bill::billNo=0;

//Initializing the Total Bill
int Parking_Bill::totalBill=0;

//Constructor for adding bill number
Parking_Bill::Parking_Bill(){
    billNo++;
}

//Parameterized Constructor
Parking_Bill::Parking_Bill(Vehicle &v, float parking_charges){
    parked_vehicle.setVehicleNum(v.getVehicleNum());
    parked_vehicle.setVehicleType(v.getVehicleType());
    parked_vehicle.setParkingHrs(v.getParkingHrs());
    parked_vehicle.setParkingId(v.getParkingId());
    Vehicle::totalVehicle+=1;
}

//Setting the parking charges for 2 wheeler
void Parking_Bill::setParkingCharges2wheelers(){
    std::cout<<"Parking charges for two wheeler vehicles: "<<std::endl;
    parking_charges_2wheelers[0] = 10;
    parking_charges_2wheelers[1] = 20;
    parking_charges_2wheelers[2] = 30;
    parking_charges_2wheelers[3] = 100;
    for(int i=0;i<4;i++){
        std::cout<<parking_charges_2wheelers[i]<<std::endl;
    }
}

//Setting the parking charges for 4 wheeler
void Parking_Bill::setParkingCharges4wheelers(){
    std::cout<<"Parking charges for four wheeler vehicles: "<<std::endl;
    parking_charges_4wheelers[0] = 20;
    parking_charges_4wheelers[1] = 30;
    parking_charges_4wheelers[2] = 40;
    parking_charges_4wheelers[3] = 200;
    for(int i=0;i<4;i++){
        std::cout<<parking_charges_4wheelers[i]<<std::endl;
    }
}

//Calculating the bill
int Parking_Bill::CalculateBill(){
    int val=0;
    if(parked_vehicle.getVehicleType()==TWOWH){
        if(parked_vehicle.getParkingHrs()<=3){
            return 10*parked_vehicle.getParkingHrs();
        }
        else if(parked_vehicle.getParkingHrs()>3 && parked_vehicle.getParkingHrs()<=6){
            return 20*parked_vehicle.getParkingHrs();
        }
        else if(parked_vehicle.getParkingHrs()>6 && parked_vehicle.getParkingHrs()<=12){
            return 30*parked_vehicle.getParkingHrs();
        }
        else{
            return 100*parked_vehicle.getParkingHrs();
        }
    }else{
        if(parked_vehicle.getParkingHrs()<=3){
            return 20*parked_vehicle.getParkingHrs();
        }
        else if(parked_vehicle.getParkingHrs()>3 && parked_vehicle.getParkingHrs()<=6){
            return 30*parked_vehicle.getParkingHrs();
        }
        else if(parked_vehicle.getParkingHrs()>6 && parked_vehicle.getParkingHrs()<=12){
            return 40*parked_vehicle.getParkingHrs();
        }
        else{
            return 200*parked_vehicle.getParkingHrs();
        }
    }
}

//Instream for taking the input
std::istream & operator>>(std::istream &in, Parking_Bill &p){

    in>>p.parked_vehicle;
    std::cout<<"Enter Parking Charges: ";
    in>>p.parking_charges;
    return in;
}

//Outstream for printing the values
std::ostream & operator << (std::ostream &out, Parking_Bill &p){
    out<<"Bill Number: "<<Parking_Bill::billNo;
    out<<p.parked_vehicle<<std::endl;
    out<<"Parking Charges: "<<p.CalculateBill()<<std::endl;
    Parking_Bill::totalBill+=p.CalculateBill();
    return out;
}
