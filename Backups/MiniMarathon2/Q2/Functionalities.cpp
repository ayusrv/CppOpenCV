#include "Functionalities.h"


//Creating the object
std::function<void(Container&)> CreateObjects = [](Container& data)
{
    data.push_back(std::make_shared<Product>("P101", ProductType::FOOD, 200.5f,  "Haldiram",ProductOrigin::DOMESTIC, 12.5f));
    data.push_back(std::make_shared<Product>("P202", ProductType::APPLIANCE, 500.5f, "LG", ProductOrigin::IMPORTED, 14.5f));
    data.push_back(std::make_shared<Product>("P303", ProductType::FOOD, 400.5f, "Lays",ProductOrigin::DOMESTIC, 15.5f));
    data.push_back(std::make_shared<Product>("P404", ProductType::PERFUME, 900.5f, "Fog", ProductOrigin::IMPORTED, 17.5f));
};

//Calculating the average Price
std::function<float(Container&, ProductType)> AveragePrice = [](Container& data, ProductType product_type)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    if(product_type!=ProductType::APPLIANCE || product_type!=ProductType::FOOD ||
    product_type!=ProductType::PERFUME)
    {
        throw EnumNotFound("Product Type not matched with the provided input");
    }
    float averagePrice=0;
    int totalCount = 0;
    for(Type t : data){
        if(t->productType()==product_type){
            averagePrice+=t->productPrice();
            totalCount++;
        }
    }
    return averagePrice/totalCount;
};

//Displaing the N AMOUNTS
std::function<void(Container&, unsigned int)> DisplayNTaxAounts = [](Container& data, unsigned int n)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    std::cout<<"Displaying the first "<<n<<" Instances: "<<std::endl;
    for(Type t : data)
    {
        if(n==0) break;
        std::cout<<t->productTax()<<std::endl;
        n--;
    }
};

//Displaying the product tax amount
std::function<void(Container&)> ProductTaxAmount = [](Container& data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    for(Type t : data){
        if(t->productTax()>=500)
        {
            std::cout<<"Product Tax is more than 500";
            return;
        }
    }
    std::cout<<"All the product tax is less than 500";
};

//Print the group categpry
std::function<void(Container&)> PrintGroupCategory = [](Container& data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
    for(Type t: data){
        if(t->productType() == ProductType::APPLIANCE)
        {
            if(t->productOrigin() == ProductOrigin::DOMESTIC)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        else if(t->productType()==ProductType::FOOD)
        {
            if(t->productOrigin() == ProductOrigin::DOMESTIC)
            {
                c3++;
            }
            else
            {
                c4++;
            }
        }
        else
        {
            if(t->productOrigin() == ProductOrigin::DOMESTIC)
            {
                c5++;
            }
            else
            {
                c6++;
            }
        }
    }

    std::cout<<"Total product or Product Type: APPLIANCE and Product Origin: DOMESTIC"<<c1<<std::endl;

    std::cout<<"Total product or Product Type: APPLIANCE and Product Origin: IMPORTED"<<c2<<std::endl;

    std::cout<<"Total product or Product Type: FOOD and Product Origin: DOMESTIC"<<c3<<std::endl;

    std::cout<<"Total product or Product Type: FOOD and Product Origin: IMPORTED"<<c4<<std::endl;

    std::cout<<"Total product or Product Type: PERFUME and Product Origin: DOMESTIC"<<c5<<std::endl;

    std::cout<<"Total product or Product Type: PERFUME and Product Origin: IMPORTED"<<c6<<std::endl;
};

//Printing the same same brand
std::function<Container(Container&, std::string)> SameBrand = [](Container& data, std::string BrandName)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    Container p;
    for(Type t : data)
    {
        if(t->productBrand() == BrandName){
            p.push_back(t);
        }
    }
    return p;
};

//Adapter
Container Adapter(std::function<Container(Container&, std::vector<std::function<Container(Container&, unsigned int)>>)>fun, Container& data, std::vector<std::function<Container(Container&, unsigned int)>> ContainerObjects)
{
    return fun(data, ContainerObjects);
}