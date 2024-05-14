#include <iostream>
#include <vector>

std::vector<int> FindOddNumbers(std::vector<int>& data){
    std::vector<int> result;
    for(int val : data){
        if(val%2!=0)
            result.push_back(val);
    }
    return result;
}

int main(){
    std::vector<int> data = {10,12,13,14,15};
    //If ke ander wo condition daal do result wala jisse if else khtm to wo conatiner v khtm and then semicolon k baad if ka logic likho jaise if(result.empty()) dalna tha to wo semicolon k baad likhe hai9
    if(std::vector<int> result = FindOddNumbers(data); result.empty())
    {
        std::cout<<"Empty container";
    }else
    {
        for(int val : data)
        {
            std::cout<<val <<" ";
        }
    }
    std::cout<<"\n";
}