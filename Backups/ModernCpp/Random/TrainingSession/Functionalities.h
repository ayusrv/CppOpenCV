#include "TrainingSession.h"
#include "TrainingBatch.h"

using Container = std::vector<TrainingBatch*>;

void createObject(std::vector<TrainingBatch*> &data);
void printObject(std::vector<TrainingBatch*> &data);
void deleteObject(std::vector<TrainingBatch*> &data);