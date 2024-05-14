#include "Functionalities.h"
#include <memory>
#include <functional>

void CreateObject(Container &data1, classAContainer &data2)
{
    data2 = std::make_shared<classA>(10,10);
    data1.push_back(std::make_shared<Major>(101,"Ayush",*data2));
}

void operations(std::function<void(int, int)> fn, int n1, int n2){
        fn(n1,n2);
    }
void getVal(Container &data1)
{
    operations([&](int n1, int n2){data1[0]->classa().get().sum(n1,n2);},10,20);
    // data1[0]->operations(std::bind(&classA::substract, data1[0]->classa().get(), std::placeholders::_1, std::placeholders::_2),
    // 10,20
    // );

    //std::bind(&className::mumberFunctionName, object(jis class ka member function hai uska object banana hai), data1, data2);
    //std::bind(&fnName, data1, data2)

    //Quets -> reference wrapper, function pointer, function wrapper, bind, lambda functions

}
