#include<iostream>

enum Rank{
    FIRST,
    SECOND,
    THIRD
};

enum Gear{
    FIRST,
    SECOND,
    THIRD
};

enum Position{
    FIRST,
    SECOND,
    THIRD
};

enum class Rank1{
    FIRST,
    SECOND,
    THIRD
};

enum class Gear1{
    FIRST,
    SECOND,
    THIRD
};

enum class Position1{
    FIRST,
    SECOND,
    THIRD
};

void Magic(int number){
    std::cout<<number*number<<"\n";
}

int main(){
    //We cannot force the user to use enum name as a prefix
    enum Rank r1 = Rank::FIRST;
    enum Gear g1 = Gear::FIRST;

    //COmpiler should block comparison of enums of different types but we will face the issue on the runtime
    if(r1==g1) std::cout<<"OOPS!! Types are different but the data is getting matched"<<std::endl;

    //Automatic conversion of ENum into the intger
    Magic(r1);

    enum Rank1 r2 = Rank1::FIRST;
    enum Gear1 g2 = Gear1::FIRST;
    // if(r2==g2) std::cout<<"OOPS!! Types are different but the data is getting matched"<<std::endl; cannot compare

    // Magic(r2); Cannot be get converted
}