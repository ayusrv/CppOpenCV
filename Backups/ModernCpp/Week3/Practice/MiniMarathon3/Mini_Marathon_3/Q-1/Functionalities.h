#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "DataOperation.h"
#include "EmptyContainerException.h"
#include "InvalidException.h"
#include <mutex>
#include <condition_variable>

extern std::mutex mt;
extern std::condition_variable cv;
extern bool flag;

void TakeInput(OperationPointer& data);

void FindMax(OperationPointer& data);

void SumOfFirstN(OperationPointer& data, int n);

void FindNthValue(OperationPointer& data, int n);

void FindOddNUmber(OperationPointer& data);

void FindFactorial(OperationPointer& data);

void checkPrime(OperationPointer& data);

#endif // FUNCTIONALITIES_H
