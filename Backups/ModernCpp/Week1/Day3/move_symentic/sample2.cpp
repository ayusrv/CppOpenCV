#include <iostream>
#include <vector>

/*
    Magic is a function that accepts 1
   standard vector of integers by value
   Magic returns void 
*/

void Magic(std::vector<int> data){

}

int main(){
    Magic(std::vector<int> {1,2,3,4,5});
    std::cout<<sizeof(main);
}

/*
    std::vector<int> data = std::vector<int> {1,2,3,4,5} 
    basically converting rvalue to lvalue so this will also work fine
*/