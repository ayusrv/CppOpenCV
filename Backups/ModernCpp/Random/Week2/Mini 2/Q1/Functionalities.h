#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<array>
#include<functional>

// lambda function to calculate the sum of values in each row

extern std::function<int(int arr[2][2])> SumOfRow;

// lambda function to displays the highest value from matrix

extern std::function<int(int arr[2][2])> HighestValueOfMatrix;

//lambda function to display square of the number at last position


extern std::function<int(int arr[2][2])> SquareOfLastElement;

//lambda function to display sum of values in each column

extern std::function<int(int arr[2][2])> SumOfColoumn;




#endif // FUNCTIONALITIES_H
