#include "Functionalities.h"

int main()
{
    Container data;
    CreateObjects(data);
    try
    {
        std::cout<<"Average Price: "<<AveragePrice(data, ProductType::FOOD)<<std::endl;

        auto NBind = std::bind(DisplayNTaxAounts, data, std::placeholders::_1);

        auto ThreeBind = std::bind(DisplayNTaxAounts, data, 3);

        NBind(2);

        ProductTaxAmount(data);

        PrintGroupCategory(data);

        Container res = SameBrand(data, "Fog");

        for(Type t : res)
        {
            std::cout<<*t<<std::endl;
        }
        
        ThreeBind();
        
    }
    catch(const EmptyContainerException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(const EnumNotFound& e)
    {
        std::cout<<e.what();
    }
    
}