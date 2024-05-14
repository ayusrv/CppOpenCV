#include "Functionalities.h"
#include <iostream>
#include <vector>
int main(){
    // std::vector<TrainingBatch*> &data;
    std::vector<TrainingBatch*> data;
    createObject(data);
    printObject(data);
    deleteObject(data);
}