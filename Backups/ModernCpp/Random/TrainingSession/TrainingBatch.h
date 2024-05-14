#ifndef TRAININGBATCH_H
#define TRAININGBATCH_H

#include <iostream>
#include "ID.h"
#include "Employee.h"
#include "Talent.h"
#include "TrainingSession.h"
#include <vector>
class TrainingBatch : public TrainingSession
{
private:
    ID* _id;
    unsigned int _strength;
    Employee* _trainer;
    Employee* _pmt_coordinator;
    std::vector<Talent*> _talents;
    TrainingSession* _training_session;

public:
    TrainingBatch() = delete;
    TrainingBatch(const TrainingBatch&) = default;
    TrainingBatch(TrainingBatch&&) = delete;
    TrainingBatch& operator = (const TrainingBatch&) = default;
    TrainingBatch&& operator = (TrainingBatch&&) = delete;

    unsigned int strength() const { return _strength; }
    void setStrength(unsigned int strength) { _strength = strength; }

    ID* id() const { return _id; }
    void setId(ID* &id) { _id = id; }

    Employee* trainer() { return _trainer; }
    void setTrainer(Employee* trainer) { _trainer = trainer; }

    Employee* pmtCoordinator() { return _pmt_coordinator; }
    void setPmtCoordinator( Employee* pmt_coordinator) { _pmt_coordinator = pmt_coordinator; }

    std::vector<Talent*> getTalents() const { return _talents; }
    void setTalents(const std::vector<Talent*> &talents_) { _talents = talents_; }

    friend std::ostream &operator<<(std::ostream &os, const TrainingBatch &rhs);

    TrainingBatch(ID* id, unsigned int strength, Employee* trainer, Employee* pmt_coordinatotr, std::vector<Talent*> Talents, TrainingSession* ts);

    TrainingSession* trainingSession() const { return _training_session; }
    void setTrainingSession(TrainingSession* training_session) { _training_session = training_session; }

    std::vector<Talent*> talents() const { return _talents; }
    // void setTalents(const std::vector<Talent*> &talents) { _talents = talents; }
};

#endif // TRAININGBATCH_H