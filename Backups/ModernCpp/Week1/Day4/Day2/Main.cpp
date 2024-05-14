/*

Main -> Vector ka object banaye isme 3 cheej aayeaga
        [Vector ka first value oa address, Vector ka last element ka address, 
        last elemnt jitna vector mai jaa skta hai uska address]

Car -> phele name daale phir price phir engine pointer same address phir type
            Dezire          180000      0X89077H                    Sedan

Enginer -> Isme HorsePower ayeaga phir torque
                300                     200
            lekin enigne address 0X89077H hoga

*/

#include <iostream>
#include <array>
#include "Functionalities.h"
#include "IdNotFoundException.h"
#include "EmptyContainerException.h"

int main(){
        Conatiner data;
        createObjects(data);
        try{
                int ans = TotalHoursePower(data);
                std::cout<<"Total HorsePower is: "<<ans<<"\n";

                float result = AverageEngineTorque(data);
                std::cout<<"Average is : "<<result<<"\n";
                
                std::string model = FindCarModelByID(data, "c101");
                std::cout<<"Model of the car : "<<model<<"\n";

                bool flag = IsContainerAllCarAbove700000(data);
                if(flag) std::cout<<"All vehicles are  above 7 Lakh "<<"\n";
                else std::cout<<"All vehicles are not above 7 Lakh "<<"\n";

                Engine* e = EnginePointerToMinPriceCar(data);
                std::cout<<"Engine Found:"<<*e; 
        
        }catch(const EmptyContainerException& ex){
                std::cout<< ex.what() <<"\n";
        }
        catch(const IdNotFoundException& ex){
                std::cout<< ex.what()<<"\n";
        }
        // deleteObjects(data);

}