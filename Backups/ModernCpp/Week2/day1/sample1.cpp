/*




*/

#include <iostream>

void square(int number){
    std::cout<<"Square of number is: "<<number*number<<"\n";
}

void cube(int number){
    std::cout<<"cube of number is: "<<number*number*number<<"\n";
}

//Higher order function 
// a higher order function either accepts or return  (or both) another function
void Operation(int* arr, int size, void (*ptr)(int)){
    for(int i=0;i<size;i++){
        (*ptr)(arr[i]);
    }
}

int main(){
    //fn pointer
    // void square(int);
    // void (*ptr)(int) = square; //Function pointer

    //void cuber(int);
    // void (*ptr2)(int) = cube; //Function pointer

    int arr[5] = {10,20,30,40,50};
    Operation(arr, 5, square);
}

/*
    Higher order functions!
    Anpnymous function 
    functional progra,,ing paradigm
    immutable data
    currying
    First-class functions

*/