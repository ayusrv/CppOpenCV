#include <iostream>
#include <functional>
#include <vector>

void Adapter(std::vector<int> &data, std::function<void(int)> fn){
    for(int i : data){
        fn(i);
    }
}

class A{
    public: 
        void sum(int a, int b){
            std::cout<<a+b<<std::endl;
        }
        void mul(int a, int b){
            std::cout<<a*b<<std::endl;
        }        

        void operations(std::function<void(A*, int, int)> fn, int a, int b){
            fn(this, a,b);
        }
};
int main(){
    // std::vector<int> v {1,2,3,4};
    // Adapter(
    //     v,
    //     [](int num){std::cout<<num;}
    // );
    std::cout<<std::endl;
    A a;
    // a.operations(
    //     [&](A* obj,int x, int y){obj->mul(x,y);}, 10, 10
    // );
    std::function<void(A*, int, int)> fun = [&](A* obj, int n1, int n2){obj->sum(n1,n2);};
    a.operations(fun, 10,10);

}