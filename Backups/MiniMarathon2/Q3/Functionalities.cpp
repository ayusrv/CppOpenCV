#include "Functionalities.h"

//Creating the object
void CreateObject(InvoiceContainer& data1, Container& data2)
{
    data1.push_back(std::make_shared<Invoice>("I101", InvoiceType::E_BILL, 2));
    data1.push_back(std::make_shared<Invoice>("I202", InvoiceType::E_BILL, 3));
    data1.push_back(std::make_shared<Invoice>("I303", InvoiceType::E_BILL, 4));
    data1.push_back(std::make_shared<Invoice>("I405", InvoiceType::E_BILL, 5));

    data2.push_back(std::make_shared<Bill>(200, 180, *data1[0]));
    data2.push_back(std::make_shared<Bill>(300, 280, *data1[1]));
    data2.push_back(std::make_shared<Bill>(400, 380, *data1[2]));
    data2.push_back(std::make_shared<Bill>(500, 480, *data1[3]));
}

//Returning the highest bill amount invoice number
LambdaFuntions InvoiceNum = [](InvoiceContainer& data1, Container& data2)
{   
    if(data1.empty())
    {
        throw EmptyContainerException("EMpty COnatiner");
    }
    int billAMount = 0;
    for(std::shared_ptr<Bill> b : data2){
        if(b->billAmount()<b->billAmountTax()){
            throw BillAmountException("Amount is less than the Tax");
        }
        if(billAMount<b->billAmount()){
            billAMount = b->billAmount();
        }
    }
    return billAMount;
};

//Cheking the tax amount
bool BillTaxAm(InvoiceContainer& data1, Container& data2)
{
    if(data1.empty())
    {
        throw EmptyContainerException("EMpty COnatiner");
    }
    for(std::shared_ptr<Bill> b : data2){
        if(b->billAmount()<b->billAmountTax()){
            throw BillAmountException("Amount is less than the Tax");
        }
        if(b->billAmount()<6000)
        {
            return false;
        }
    }
    return true;
}

//Returning the bill invoice amount
std::function<Container(InvoiceContainer&, Container&, int amount)> BillInvoiceAm = [](InvoiceContainer& data1, Container& data2, int amount)
{
    if(data1.empty())
    {
        throw EmptyContainerException("EMpty COnatiner");
    }
    Container c;
    for(std::shared_ptr<Bill> b : data2)
    {
        if(b->billAmount()<b->billAmountTax()){
            throw BillAmountException("Amount is less than the Tax");
        }
        if(b->billAmount()<amount)
        {
            c.push_back(b);
        }
    }
    return c;
};

//Return the invoice type that has been passed
std::function<InvoiceType(InvoiceContainer&, Container&, std::string)> InvoiceNumberType = [](InvoiceContainer& data1, Container& data2, std::string invoiceNum)
{
    InvoiceType t;
    for(Pointer p : data1){
        if(p->invoiceNumber() == invoiceNum)
        {
            t=p->invoiceType();
        }
    }
    return t;
};