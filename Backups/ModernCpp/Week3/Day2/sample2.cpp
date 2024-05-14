//Templates + recursion -> Variadic templates

#include <iostream>

/*
    Add is a funcyion that takes 1 parameters of type "int" It uses them as oprands for binary + operatorand returns the result of + operator applied on these operands
*/
template <typename T>
T add(T n1){
    return n1;
}
//...-> multiple number of type name
template <typename T, typename... Remaining>
T add(T n1, Remaining... args){
    return n1+add(args...);
}

int main(){
    std::cout<<add<int>(10,20,30,40,50)<<"\n";
    std::cout<<add<std::string>("Ayush"," Srivastava")<<"\n";
}