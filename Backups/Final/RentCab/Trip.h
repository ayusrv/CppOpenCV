#ifndef TRIP
#define TRIP
#include<iostream>

enum Ride{REGULAR, COMFORT, PREMIUM};
class Trip{
    private:
        std::string tripId;
        std::string tripDriver;
        int tripDistance;
        int tripRating;
        Ride tripVehicleType;

    public:
        Trip();

        std::string getTripId() const;
        void setTripId(const std::string &tripId_);

        std::string getTripDriver() const;
        void setTripDriver(const std::string &tripDriver_);

        int getTripDistance() const;
        void setTripDistance(int tripDistance_);

        int getTripRating() const;
        void setTripRating(int tripRating_);

        Ride getTripVehicleType() const;
        void setTripVehicleType(const Ride &tripVehicleType_);

        virtual void calculateFare() = 0;
        
};

#endif