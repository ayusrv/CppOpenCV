#include<iostream>
#include"Functionalities.h"

int main(){

 int arr[2][2] ={{10,20},{30,40}};

 SumOfRow(arr);

 int HigestValue = HighestValueOfMatrix(arr);
  std::cout<<"Highest Value = "<<HigestValue<<"\n";

  int Square = SquareOfLastElement(arr);
  std::cout<<" Square of Last Number = "<<Square<<"\n";

SumOfColoumn(arr);




}