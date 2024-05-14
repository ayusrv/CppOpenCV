#include "Functionalities.h"

int main()
{
    Container data1;
    UnitContainer data2;
    createObject(data1, data2);
    HighOrder(data1, PrintCertainData);
    HighOrder(data1, PrintMaximum);
    HighOrder(data1, getOdd);
}