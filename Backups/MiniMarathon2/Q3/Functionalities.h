#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Bill.h"
#include <vector>
#include "EmptyContainerException.h"
#include "BillAmountException.h"

using Pointer = std::shared_ptr<Invoice>;
using InvoiceContainer = std::vector<Pointer>;
using Container = std::vector<std::shared_ptr<Bill>>;
using LambdaFuntions = std::function<int(InvoiceContainer&, Container&)>;

void CreateObject(InvoiceContainer& data1, Container& data2);

extern LambdaFuntions InvoiceNum;

extern std::function<InvoiceContainer(InvoiceContainer&, Container&, InvoiceType)> InvoiceTypes;

bool BillTaxAm(InvoiceContainer& data1, Container& data2);

extern std::function<Container(InvoiceContainer&, Container&, int amount)> BillInvoiceAm;

extern std::function<InvoiceType(InvoiceContainer&, Container&, std::string)> InvoiceNumberType;



#endif // FUNCTIONALITIES_H
