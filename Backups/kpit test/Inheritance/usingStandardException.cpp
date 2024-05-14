#include<iostream>
#include<exception>
using namespace std;

// class myException: public exception{
//     virtual const char* what() const throw(){
//         return "my exception occoured";
//     }
// }myex;

class overspeed: public exception{
    int speed;
    public:
    const char* what(){
        return "Check out your speed you are in car not in aeroplane";
    }
};

int main(){
    // try{
    //     throw myex;
    // }catch(exception e){
    //     cout<< e.what()<<"\n";
    // }

    int carspeed=0;
    try{
        while(1){
            carspeed+=10;
            if(carspeed>100){
                overspeed s;
                throw s;
            }
            cout<<"CarSpeed: "<<carspeed<<endl;
        }
    }
    catch(overspeed ex){
        cout<<ex.what();
    }
    return 0;
}