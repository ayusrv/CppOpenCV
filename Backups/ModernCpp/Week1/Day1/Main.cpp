#include "Functionalities.h"
#include <vector>


int main(){
    std::vector<Car*>data;
    CreateObjects(data);
    PrintObject(data);
    DeleteObject(data);
}