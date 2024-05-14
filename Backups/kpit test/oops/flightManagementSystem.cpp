// This code will show the flight what we want to search, the total fare of the flight and the fuel it will consume

#include <bits/stdc++.h>
using namespace std;

class flightManagement
{
    // Assigning the data members
    string flightNumber;
    double distance;
    string flightType;
    double fuelQuantity;
    double fare;

public:
    // Default Constructor
    flightManagement()
    {
        flightNumber = "BA1000";
        distance = 0;
        flightType = "International";
        fuelQuantity = 0;
        fare = 0;
    }

    // Parameterized Constructor
    flightManagement(string flightNumber, double distance, string flightType)
    {
        this->flightNumber = flightNumber;
        this->distance = distance;
        this->flightType = flightType;
    }

    // setter for FLight Number
    void setFlightNumber(string flightNumber)
    {
        this->flightNumber = flightNumber;
    }

    // Setter for Distance
    void setDistance(double distance)
    {
        this->distance = distance;
    }

    // Setter for Flight Types
    void setFlightType(string flightType)
    {
        this->flightType = flightType;
    }

    // Getter for Flight Number
    string getFlightNumber()
    {
        return flightNumber;
    }

    // Getter for Distance
    double getDistance()
    {
        return distance;
    }

    // Getter for Flight Type
    string getFlightType()
    {
        return flightType;
    }

    // Getter for Fuel Quantity
    double getFuelQuantity()
    {
        return calculateFuel();
    }

    // Getter for Fare
    double getFare()
    {
        return calculateFare();
    }

    // Calculate the fare of the flights
    int calculateFare()
    {
        if (distance <= 1000)
            this->fare = 5000;
        else if (distance > 1000 && distance <= 1500)
            this->fare = 11000;
        else if (distance > 1500 && distance <= 2000)
            this->fare = 22000;
        else
            this->fare = 30000;
        return this->fare;
    }

    // Calculate Fuel of the flights
    int calculateFuel()
    {
        if (distance <= 1000)
            this->fuelQuantity = 4000;
        else if (distance > 1000 && distance <= 1500)
            this->fuelQuantity = 6000;
        else if (distance > 1500 && distance <= 2000)
            this->fuelQuantity = 7500;
        else
            this->fuelQuantity = 10000;
        return this->fuelQuantity;
    }

    // Feed Info to store the information
    void feedInfo(string flightNumber, double distance, string flightType)
    {
        this->flightNumber = flightNumber;
        this->distance = distance;
        this->flightType = flightType;
    }

    // Display Function to display the informations
    void display()
    {

        cout << "Flight Number is: " << this->flightNumber << endl;
        cout << "Total Distance: " << this->distance << endl;
        cout << "Flight Type: " << this->flightType << endl;
        cout << "Fuel Quantity: " << calculateFuel() << endl;
        cout << "Total Fare: " << calculateFare() << endl;
    }
};

int main()
{
    flightManagement fm[3];

    // Giving mx=0 to store the max values, ind=-1 to store the index of the flight who is having maximum value
    int mx = 0, ind = 0;
    cout << "Please enter the details of the flight: " << endl;
    for (int i = 0; i < 3; i++)
    {
        string flightNumber;
        double distance;
        string flightType;

        cout<<"\n";

        // ENtering all the details
        cout << "Enter the Flight Number of " << i + 1 << " flight: ";
        cin >> flightNumber;
        cout << "Enter the distance will be travelled by " << i + 1 << " flight: ";
        cin >> distance;
        cout << "Enter the Flight Type of the " << i + 1 << " Flight: ";
        cin >> flightType;

        // Feeding the values
        fm[i].feedInfo(flightNumber, distance, flightType);

        // Calculate the values
        if (mx < fm[i].calculateFare())
        {
            mx = fm[i].calculateFare();
            ind = i;
        }

        // Displaying all the details
        fm[i].display();
    }

    // details to search the flight
    cout << "Enter the flight number you want to search: ";
    string userFLight;
    cin >> userFLight;
    int flag=0;

    // Searching the flight by traversing the array
    for (int i = 0; i < 3; i++)
    {
        if (fm[i].getFlightNumber() == userFLight)
        {
            fm[i].display();
            flag=1;
        }
    }
    if(!flag) cout<<"The flight you have searched is not found!!";

    // Printing the maximum value
    cout << "The maximum fare of the flight is: ";
    fm[ind].display();
}