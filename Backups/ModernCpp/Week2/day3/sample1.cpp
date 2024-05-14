//bind

/*
    1) we cannot massively change code after it is deployed for client
    2) Sometimes API parameters need to be fixed at certain value
            Connection(ip,port, hostname, id, pass) ye tum user ko de diye ho or aab tumko 
            COnnection(hostname, id, pass) hi vejna hai and ip=192.17.18 port=22 set krna hai 
                                    change kr nahi skte ho aab kyuki user k pass code jaa chuka hai 
*/

//A function variable notes the address of the first instruction

#include <iostream>
#include <functional>
#include <list>
#include <cstring>

void Formula(const int x, const int y, const int z){
    std::cout<<"Answer is: "<<((x+y)-z)<<"\n";
}


float Formula2(const int x, const int y, const int z){
    return z*10.4;
}

void Magic(const std::list<int> &data, int n){
    for(int val: data){
        n--;
        if(n==0){
            std::cout<<val<<"\n";
        }
    }
}

int main(){
    Formula(10,20,30); //X=10, Y=20, Z=30
    //Set the value of x in formula too fixed forever!

    //Binded likne ka tarika
    auto binded_formula = std::bind(&Formula, 100, std::placeholders::_1, std::placeholders::_2);

    //Placeholder::_1 -> 1st number user gives wo y mai jayeaga
    binded_formula(30,40); //x=100, y=30, z=40
    binded_formula (10,20,32); //3rd wala discard hoga x=100, y=10, z=20

    auto binded_formula2 = std::bind(&Formula2, 100, std::placeholders::_1, std::placeholders::_2);
    std::cout<<binded_formula2(20,31)<<"\n";

    auto binded_Magic = std::bind(&Magic, std::placeholders::_2, std::placeholders::_1);

    auto binded_strcpy = std::bind(&strcpy, std::placeholders::_2, std::placeholders::_1);
    char* msg;
    msg = new char[6];
    binded_strcpy("Ayush",msg);
    std::cout<<msg<<"\n";
    delete[] msg;

    //a lambda is an object, using & on a lambda means address of an object
    //Don't use & sign with lmbda
    auto fun=[](int number, int factor){std::cout<<number*factor<<std::endl;};
    auto binded_lambda_fn = std::bind(fun, std::placeholders::_1, 40);
    binded_lambda_fn(100,40); //fun(100,40)
    binded_lambda_fn(100,20); //fun(100,40)

    

}


//ashish.rawat@kpit.com