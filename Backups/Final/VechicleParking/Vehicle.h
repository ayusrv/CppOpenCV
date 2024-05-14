#ifndef VEHICLE
#define VEHICLE

#include<iostream>
enum types{TWOWH, FOURWH};

class Vehicle{
    private:
        char* vehicleNum;
        types vehicle_type;
        int parking_hrs;
        int parking_id;

    public:
        
        //Staic in total vehicle
        static int totalVehicle;

        //Default Constructor
        Vehicle();

        //Getter Setter for vehicle number
        char* getVehicleNum();
        void setVehicleNum(char* vehicleNum_);

        //Getter Setter for the Vehicle Types
        types getVehicleType();
        void setVehicleType(const types &vehicleType);

        //Getter Setter for parking hours
        int getParkingHrs();
        void setParkingHrs(int parkingHrs);

        //Getter setter for PakringId
        int getParkingId();
        void setParkingId(int parkingId);
        
        //Taking input for the Vehicle
        friend std::istream & operator>>(std::istream& in, Vehicle &v);

        //Printing the output for the Vehicle
        friend std::ostream & operator<<(std::ostream& out, Vehicle &v);

        //Shwoing the total number of vehicles
        void showVehicle();
};

#endif