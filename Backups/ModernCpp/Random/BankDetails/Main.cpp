#include "Functionalities.h"
#include <vector>

int main(){
    Container data;
    CreateObject(data);
    PrintObject(data);
    std::cout<<std::endl<<std::endl<<MinimumBalance(data);
    DeleteObject(data);
}