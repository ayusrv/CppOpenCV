#include "Functionalities.h"


OperationPointer DataOperation::_solo_hero_obj{nullptr};
std::mutex mt;
std::condition_variable cv;
bool flag=false;

void TakeInput(OperationPointer& data)
{
    int magic=0;
    std::cin>>magic;
    data=DataOperation::getfirstInstances(magic);
    flag=true;
    cv.notify_one();
}

void FindMax(OperationPointer &data)
{
    if(data==nullptr){
        throw EmptyContainerException("Data Not Found");
    }
    int max=0;
    for(int i:data->dataVector()){
        if(i>max){
            max=i;
        }
    }
    std::cout<<"Max is: "<<max<<std::endl;
}

void SumOfFirstN(OperationPointer &data, int n)
{
    if(data==nullptr){
        throw EmptyContainerException("Data Not Found");
    }
    int sum=0;
    for(int i:data->dataVector()){
        if(n==0){
            break;
        }
        sum+=i;
        n--;
    }
    std::cout<<"Sum is: "<<sum<<std::endl;
}

void FindNthValue(OperationPointer &data, int n)
{
    if(data==nullptr){
        throw EmptyContainerException("Data Not Found");
    }
    int ans = data->dataVector()[n-1];
    std::cout<<"Nth Index value is is: "<<ans<<std::endl;
}

void FindOddNUmber(OperationPointer &data)
{
    if(data==nullptr){
        throw EmptyContainerException("Data Not Found");
    }
    std::cout<<"Odd Numbers are: "<<std::endl;
    for(int i:data->dataVector()){
        if(i%2!=0){
            std::cout<<i<<std::endl;
        }
    }
}

void FindFactorial(OperationPointer &data)
{
    if(data==nullptr){
        throw EmptyContainerException("Data Not Found");
    }
    int n=data->magicNumber();
    if(n<1 || n>10){
        throw InvalidException("Invalid Number!");
    }
    int f=1;
    for(int i=1; i<=n; i++){
        f*=i;
    }
    std::cout<<"Factorial is: "<<f<<std::endl;
}

void checkPrime(OperationPointer &data)
{
    if(data==nullptr){
        throw EmptyContainerException("Data Not Found");
    }
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [](){
        return flag;
    });
    int n=data->magicNumber();
    for(int i=1; i<=n/2; i++){
        if(n%i==0){
            std::cout<<"Not a Prime Number"<<std::endl;
            return;
        }
    }
    std::cout<<"Prime Number"<<std::endl;
}
