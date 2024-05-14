#include "TrainingBatch.h"
std::ostream &operator<<(std::ostream &os, const TrainingBatch &rhs) {
    os << "Id: " << rhs.id()->CountryToString(rhs.id()->country()) << rhs.id()->year() << rhs.id()->month() << rhs.id()->LevelToString(rhs.id()->track()) << rhs.id()->batchNumber() << rhs.id()->LocationToString(rhs.id()->location()) << rhs.id()->TrackNameToString(rhs.id()->trackName())
       << " _strength: " << rhs._strength
       << " _trainer: " << rhs._trainer
       << " _pmt_coordinator: " << rhs._pmt_coordinator;
       for(long unsigned int i=0; i<rhs._talents.size(); i++){
        os<<"Talents: "<<rhs._talents[i]<<" ";
       }
    return os;
}

TrainingBatch::TrainingBatch(ID* id, unsigned int strength, Employee* trainer, Employee* pmt_coordinatotr, std::vector<Talent *> talents, TrainingSession* ts)
              : _id(id), _strength(strength), _trainer(trainer), _pmt_coordinator(pmt_coordinatotr), _talents(talents), _training_session(ts) {}

// TrainingBatch::TrainingBatch(ID *id, unsigned int strength, Employee *trainer, Employee *pmt_coordinatotr, std::vector<Talent *> Talents, TrainingSession *ts)
//                 :_id(id),  {}
