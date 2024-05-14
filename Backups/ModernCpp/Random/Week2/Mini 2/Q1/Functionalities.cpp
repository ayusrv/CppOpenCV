#include"Functionalities.h"

std::function<int(int arr[2][2])> SumOfRow =[](int arr[2][2]){
    int sum=0;
    int i=0;
    int j=0;
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        sum += arr[i][j];
    }
    std::cout<<"Sum of Row "<<i<<" = "<<sum<<"\n";
    sum=0;

 }

    return sum;
};

std::function<int(int arr[2][2])> HighestValueOfMatrix =[](int arr[2][2]){
  int Max=arr[0][0];

    int i=0;
    int j=0;
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      if(Max < arr[i][j]){
          Max = arr[i][j];
      }
    }
}

    return Max;
};
std::function<int(int arr[2][2])> SquareOfLastElement =[](int arr[2][2]){
  int num=0;
 num= arr[1][1];

    return num*num;
};


std::function<int(int arr[2][2])> SumOfColoumn =[](int arr[2][2]){
    int sum=0;
    int i=0;
    int j=0;
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        sum += arr[i][j];
    }
    std::cout<<"Sum of Coloumn "<<j<<" = "<<sum<<"\n";
    sum=0;

 }

    return sum;
};

