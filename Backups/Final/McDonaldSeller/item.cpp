#include "item.h"

#include<bits/stdc++.h>
using namespace std;

//Handling exception for cash in hand
class excep:public exception{
    public:
        const char* what(){
            return "You don't have enogh money";
        }
};

//Assigning 100 to the cash in hand
item::item():cash_in_hand(100){}

// int item::cash_in_hand=100;

//Evaluting cash in hand
void item::sellItem(){
    if(cash_in_hand==0){
        cout<<"Your balance is zero";
        return;
    }
    cout<<"Enter which product you want: "<<endl;
    cout<<"Press 1 for Burger and 2 for Pizza "<<endl;
    cin>>prod_type;
    cout<<"Enter number of products you want: "<<endl;
    cin>>number_of_items;

    //Handling the type of item
    switch (prod_type)
    {
    case 1:
        cash_in_hand-=(number_of_items*10);
        //Exception handling for cash in hand
        try{
            //If cash in hand is less then then throw
            if(cash_in_hand<0){
                excep e;
                throw e;
            }
            cout<<"You order is ready"<<endl;
            cout<<"Happy Meal"<<endl;
            //if cash is not low then call the sell item again
            cout<<"You have choose Burger"<<endl;
            sellItem();
        }
        catch(excep e){
            cout<<e.what()<<endl;
        }
        break;
    case 2:
        //Exception handling for cash in hand
        try{
            //If cash in hand is less then throw
            if(cash_in_hand<=0){
                excep e;
                throw e;
            }
            else if((cash_in_hand-(number_of_items*20))<0){
                cout<<"You can buy Burger"<<endl;
                sellItem();
            }
            else{
                cash_in_hand-=number_of_items*20;
                cout<<"You order is ready"<<endl;
                cout<<"Happy Meal"<<endl;
                //if cash is not low then call the sell item again
                cout<<"You have choose Pizza"<<endl;
                sellItem();
            }
        }
        catch(excep e){
            cout<<e.what()<<endl;
        }
        break;

    default:
        cout<<"Wrong choice"<<endl;
        break;
    }
}