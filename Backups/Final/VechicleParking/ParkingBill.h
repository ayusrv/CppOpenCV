#ifndef PARKINGBILL
#define PARKINGBILL

#include<iostream>
#include "Vehicle.h"

class Parking_Bill{
    private:
        static int billNo;
        Vehicle parked_vehicle;
        float parking_charges;
        int parking_charges_2wheelers[4];
        int parking_charges_4wheelers[4];
    
    public:

        //Default COnstructor
        Parking_Bill();

        //Total Bill
        static int totalBill;

        //Parameterized Constructor
        Parking_Bill(Vehicle &v, float parking_charges);

        //Getter Setter for Vehicle
        Vehicle parkedVehicle() const { return parked_vehicle; }
        void setParkedVehicle(const Vehicle &parkedVehicle) { parked_vehicle = parkedVehicle; }

        //Getter Setter for Parking Charges
        float parkingCharges() const { return parking_charges; }
        void setParkingCharges(float parkingCharges) { parking_charges = parkingCharges; }
        
        //Taking input for the Parking Bill
        friend std::istream & operator>>(std::istream& in, Parking_Bill &p);

        //Printing the output for the Parking Bill
        friend std::ostream & operator<<(std::ostream& out, Parking_Bill &p);

        //Setter for the Parking vehicle charges
        void setParkingCharges4wheelers();
        void setParkingCharges2wheelers();
        
        //Calculate Bill
        int CalculateBill();

};

#endif