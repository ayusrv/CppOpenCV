#include <iostream>
#include "Functionalities.h"


int main()
{
    Container data;
    ContainerFType fun;
    CreateObjects(fun,data);

    //Try if the data is valid or not
    try{
        Adapter(fun,data);
    }

    //catch the size is invalid or not
    catch (SizeInvalidException &s)
    {
        std::cout<<s.what();
    }
}