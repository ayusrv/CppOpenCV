#include "Functionalities.h"
#include <vector>

void createObject(std::vector<TrainingBatch *> &data)
{
    // Employee* e1 = new Employee("Asif", 2192, "12/12/12", "Developer");
    // Employee* e2 = new Employee("Harshit", 2190, "14/12/12", "Trainer");
    // Employee* c1 = new Employee("Saloni", 21892, "12/12/11", "Consultant");
    // Employee* c2 = new Employee("Ayushi", 21992, "12/12/11", "Consultant");
    // ID* id1 = new ID(Country::India, 2024, 01, Level::BasicTrack, 2, Location::Pune, TrackName::CPP);
    // ID* id2 = new ID(Country::Japan, 2024, 01, Level::AdvanceTrack, 2, Location::Banglore, TrackName::C);
    std::vector<Talent*> t;
    t.push_back(new Talent("AYush", "CU", 219382));
    t.push_back(new Talent("ABhishek", "LPU",219387)); 
    // TrainingSession* ts = new TrainingSession(9, 60, "Harshit","Modern","16/02/2024");
    data.push_back(new TrainingBatch(new ID(Country::India, 2024, 01, Level::BasicTrack, 2, Location::Pune, TrackName::CPP)
                    , 66, new Employee("Harshit", 2190, "14/12/12", "Trainer")
                    , new Employee("Ayushi", 21992, "12/12/11", "Consultant")
                    , t, new TrainingSession(9, 60, "Harshit","Modern","16/02/2024")));
}

void printObject(std::vector<TrainingBatch *> &data)
{
    for(TrainingBatch* t : data){
        std::cout<<*t;
    }
}

void deleteObject(std::vector<TrainingBatch *> &data)
{
    // for(TrainingBatch *t : data){
    //     // delete t;
    //     delete t->trainer();
    //     delete t->pmtCoordinator();
    //     delete t->trainingSession();
    //     for(Talent* tt : t->talents()){
    //         delete tt;
    //     }
    //     delete t;
    // }


    for(TrainingBatch * p:data){
       delete p->id();
       delete p->trainer();
       delete p->pmtCoordinator();

       for(Talent *t:p->getTalents()){
        delete t;
       }

        delete p->trainingSession();


        delete p;


    }
}
