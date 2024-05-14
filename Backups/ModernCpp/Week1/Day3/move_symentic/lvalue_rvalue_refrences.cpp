#include<iostream>
#include<list>

void Magic(std::list<int>& data){

}

//rvalue refrences
/*
    Weird magic function can only be called by rvalue
        -> it means the user will nver be able to have two copies of data.
            One in caller(Main) function and one in callee(WeirdMagic)
*/
void WeirdMagic(std::list<int>&& data){
    std::cout<<data.size()<<"\n";
}
int main(){
    std::list<int> l1 {1,2,3,4,5}; 
    Magic(l1); //Call by lvalue refrences
    WeirdMagic(std::list<int> {1,2,3,4,5}); //Call by rvalue reference because no name is provided
                                            //Here MOV logic has been applied

    // WeirdMagic(l1); // This will give error kyuki tum bina mov k lvalue vejre ho waha wo rvalue expect krra hai
    WeirdMagic(std::move(l1)); //This will work converted lvalue to rvalue with move

    //&& se hum log bolte hai ki ye rvalue hi expect kre
}