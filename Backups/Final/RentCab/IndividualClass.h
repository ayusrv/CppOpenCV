#ifndef INDIVIDUALCLASS
#define INDIVIDUALCLASS
#include "Trip.h"
class IndividualClass{
    private:
        int individualTripDuration;
    
    public:
        IndividualClass();

        int getIndividualTripDuration() const { return individualTripDuration; }
        void setIndividualTripDuration(int individualTripDuration_) { individualTripDuration = individualTripDuration_; }
        
        void calculateFare();

        void calculateFare(float sugarcharge);

        void isTripAsPerStandard();

        
};

#endif;