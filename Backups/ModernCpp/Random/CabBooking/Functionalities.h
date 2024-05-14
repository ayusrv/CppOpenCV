#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <vector>
#include "CashPayment.h"
#include "OnlinePayment.h"
#include "EmptyContainerException.h"
#include <memory>

using CabBook = std::shared_ptr<CabBooking>;
using Container = std::vector<CabBook>;

void CreateObject(Container &data);
void DisplayObject(Container &data);
std::string FindMaxBookingID(Container &data);
Container NInstance(Container &data, int n);
bool Above1000(Container &data);

#endif // FUNCTIONALITIES_H
