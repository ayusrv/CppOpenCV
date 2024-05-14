#include "Functionalities.h"

int main()
{
  ProductContainer data;

  CreateObejects(data);
  // try
  // {

  //   float Average = AverageProductPrice(data, ProductType::FOOD);

  //   std::cout << "Average of Product Price = " << Average << "\n";
  // }
  // catch (std::runtime_error &msg)
  // {
  //   std::cout << msg.what() << std::endl;
  // }
  // try
  // {
  //   float TaxAmount = ReturnProductTaxAmount(data);
  //   std::cout << "Tax amount of product with maximum price = " << TaxAmount << "/n";
  // }
  // catch (std::runtime_error &msg)
  // {
  //   std::cout << msg.what() << std::endl;
  // }

  // std::cout << "\nLast N Instances:" << std::endl;
  // try
  // {
  //   ProductContainer n_instances = LastNInstances(data, 2);
  //   for (const auto &instance : n_instances)
  //   {
  //     std::cout << *instance << std::endl;
  //   }
  // }
  // catch (std::runtime_error &msg)
  // {
  //   std::cout << msg.what() << std::endl;
  // }

//   std::cout << "Unique Brands:" << std::endl;
  // try
  // {
  //    std::set<std::string> UniqueBrand = ReturnUniqueProductsBrand(data);
  //   for (const auto &ptr : UniqueBrand)
  //   {
  //     std::cout << ptr << std::endl;
  //   }
  // }
  // catch (std::runtime_error &msg)
  // {
  //   std::cout << msg.what() << std::endl;
  // }

//   std::cout << "\nCount:" << std::endl;
  // try
  // {
  //   std::array<int, 2> arr = ReturnCount(data);
  //   int i = 0;
  //   for (i = 0; i < 2; i++)
  //   {
  //     std::cout << arr[i] << std::endl;
  //   }
  // }
  // catch (std::runtime_error &msg)
  // {
  //   std::cout << msg.what() << std::endl;
  // }

  std::cout << "\nFirst N Instances:" << std::endl;
  try
  {
    ProductContainer adresses = ReturnAdresses(data, "Nestle");
    for ( auto &ptr : adresses)
    {
      std::cout << ptr << std::endl;
    }
  }
  catch (std::runtime_error &msg)
  {
    std::cout << msg.what() << std::endl;
  }



}

                                    

