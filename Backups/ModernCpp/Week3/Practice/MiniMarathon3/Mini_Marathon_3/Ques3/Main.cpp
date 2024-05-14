#include "Operations.h"

int main()
{
    DriverContainer data2;
    CabContainer data1;
    OperationPointer op = Operation::getInstance();
    op->CreateObject(data2, data1);
    try
    {
        VType v = 12;
        std::future<void> PM = std::async(&Operation::PaymentMode, op, std::ref(data1), std::ref(v));
        PM.get();
        std::future<void> MinMax = std::async(&Operation::MinMaxFare, op, std::ref(data1));
        MinMax.get();
        std::future<void> TI = std::async(&Operation::TakeInput, op);
        std::future<void> NI = std::async(&Operation::NInstaces, op, std::ref(data1));
        TI.get();
        NI.get();

        std::promise<int> pt;
        int k = 0;
        std::cin >> k;
        std::future<int> ft = pt.get_future();
        std::future<int> NII = std::async(&Operation::NII, op, std::ref(data1), std::ref(ft));
        pt.set_value(k);
        std::cout << NII.get();
    }
    catch(EmptyContainerException& ex)
    {
        std::cout<<ex.what()<<std::endl;
    }

    // op->PaymentMode(data1, v);
}