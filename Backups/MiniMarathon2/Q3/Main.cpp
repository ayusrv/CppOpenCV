#include "Functionalities.h"

int main()
{
    Container data1;
    InvoiceContainer data2;
    CreateObject(data2,data1);
    try{
        std::cout<<"Invoice number of highest Bill amount"<<InvoiceNum(data2, data1)<<std::endl;

        std::cout<<"Bill tax Amount: "<<BillTaxAm(data2, data1)<<std::endl;
        auto binded = std::bind(BillInvoiceAm, data2, data1, std::placeholders::_1);
        auto binded2 = std::bind(BillInvoiceAm, data2, data1, 400);

        Container res1 = binded(2);
        Container res2 = binded2();

        

    }
    catch(EmptyContainerException &e){
        std::cout<<e.what()<<std::endl;
    }
    catch(BillAmountException &b){
        std::cout<<b.what()<<std::endl;
    }
}