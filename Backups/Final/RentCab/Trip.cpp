#include "Trip.h"
#include <iostream>

Trip::Trip(){}

std::string Trip::getTripId() const { return tripId; }
void Trip::setTripId(const std::string &tripId_) { tripId = tripId_; }

std::string Trip::getTripDriver() const { return tripDriver; }
void Trip::setTripDriver(const std::string &tripDriver_) { tripDriver = tripDriver_; }

int Trip::getTripDistance() const { return tripDistance; }
void Trip::setTripDistance(int tripDistance_) { tripDistance = tripDistance_; }

int Trip::getTripRating() const { return tripRating; }
void Trip::setTripRating(int tripRating_) { tripRating = tripRating_; }

Ride Trip::getTripVehicleType() const { return tripVehicleType; }
void Trip::setTripVehicleType(const Ride &tripVehicleType_) { tripVehicleType = tripVehicleType_; }
