//Templates + recursion -> Variadic templates

#include <iostream>

/*
    Add is a funcyion that takes 1 parameters of type "int" It uses them as oprands for binary + operatorand returns the result of + operator applied on these operands
*/

//...-> multiple number of type name
template <typename... T>
auto add(T... n1){
    return (n1+...); //This is fold expression addition right side se hoga
}

template <typename... T>
auto Sub(T... n1){
    // return (n1-...);  (10-(20-(30-(40-50)))) //right associated
    return (...-n1); //((((10-20)-30)-40)-50) // left associated
}

int main(){
    std::cout<<add<int>(10,20,30,40,50)<<"\n";
    std::cout<<Sub<int>(10,20,30,40,50)<<"\n";
    std::cout<<add<std::string>("Ayush"," Srivastava")<<"\n";
}