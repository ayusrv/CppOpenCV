 #include "Functionalities.h"

void CreateObejects(ProductContainer &data)
{

    data.emplace_back(
        std::make_shared<product>(
            "1A2B",
            ProductType::FOOD,
            20.0f,
            "Nestle",
            ProductOrigin::DOMESTIC,
            5.0f

            ));
    data.emplace_back(
        std::make_shared<product>(
            "1A2B",
            ProductType::FOOD,
            10.0f,
            "Nestle",
            ProductOrigin::DOMESTIC,
            3.0f

            ));
    data.emplace_back(
        std::make_shared<product>(
            "16GG",
            ProductType::APPLIANCE,
            29000.0f,
            "Voltas",
            ProductOrigin::IMPORTED,
            2000.0f

            ));

    data.emplace_back(
        std::make_shared<product>(
            "1A2B",
            ProductType::PERFUME,
            10000.0f,
            "Ford",
            ProductOrigin::IMPORTED,
            500.0f

            ));
}

std::function<float(ProductContainer &, ProductType type)> AverageProductPrice = [](ProductContainer &data, ProductType type)
{
    float Sum = 0;
    int Count = 0;

    if (data.empty())
    {
        throw std::runtime_error("Data is Empty!");
    }

    for (auto avg : data)
    {
        if (avg->type() == type)
        {
            Sum += avg->productPrice();
            Count++;
        }
    }

    return Sum / Count;
};

std::function<float(ProductContainer &)> ReturnProductTaxAmount = [](ProductContainer &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is Empty!");
    }

    auto maxi = data.front();

    for (auto ptr : data)
    {
        if (ptr->productPrice() > maxi->productPrice())
        {
            maxi = ptr;
        }
    }
    

    return maxi->productTaxAmount();
};

std::function<ProductContainer(ProductContainer &data, int n)> LastNInstances = [](ProductContainer &data, int n)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty.");
    }

    ProductContainer result;

    auto itr = data.end();

    while (n > 0)
    {
        itr--;
        n--;
        result.emplace_back(*itr);
    }

    if (result.empty())
    {
        throw std::runtime_error("Result is empty.");
    }

    return result;
};

std::function<std::set<std::string>(ProductContainer &data)> ReturnUniqueProductsBrand = [](ProductContainer &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty.");
    }
      std::set<std::string> uniqueBrandName;

    for (const auto& ptr : data) {
    
            uniqueBrandName.emplace(ptr->productBrand());
    
    }
    return uniqueBrandName;
};

std::function<std::array<int, 2>(ProductContainer &data)> ReturnCount = [](ProductContainer &data)
{
    int FoodCount = 0;
    int DomesticCount = 0;

    if (data.empty())
    {
        throw std::runtime_error("Data is empty.");
    }

    std::array<int, 2> arr;

    for (auto ptr : data)
    {
        if (ptr->type() == ProductType::FOOD)
        {
            FoodCount++;
        }
    }
    for (auto ptr : data)
    {
        if (ptr->origin() == ProductOrigin::DOMESTIC)
        {
            DomesticCount++;
        }
    }

    arr[0] = FoodCount;
    arr[1] = DomesticCount;

    return arr;
};

std::function<ProductContainer( ProductContainer &data, std::string brand)> ReturnAdresses = [](ProductContainer &data, std::string brand){
  
  ProductContainer result;
   for ( auto &ptr : data)
    {
        if (ptr->productBrand() == brand)
        {
            result.emplace_back(ptr);
        }
    }

  return result;

};
