#include<iostream>
using namespace std;

class banking{
    static double totalBal;
    int availableBal;
    public:
    banking(){}
    banking(int bal){this->availableBal=bal; totalBal+=bal;}
    friend void withdraw(banking &b, double amount);
    friend void addMoney(banking &b, double amount);
    friend void checkBal(banking &b);
    static void getTotalBal(){
        cout<<"\nTotal Balance is "<<totalBal;
    }
};

double banking::totalBal=0;

void withdraw(banking &b, double amount){
    if(b.availableBal>=amount){
        b.availableBal-=amount;
    }else{
        cout<<"\nInsufficient balance can't withdraw";
    }
}

void addMoney(banking &b, double amount){
    b.availableBal+=amount;
    b.totalBal+=amount;
}

void checkBal(banking &b){
    cout<<"\nCurrect balance remains: "<<b.availableBal;
}

int main(){
    banking b(10000.0);
    int choice;
    int amount;
    do
    {
        cout << "\nMenu:\n1. Add Money\n2. Withdraw Money\n3. Check Balance\n4. Total Balance\n5. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter the amount you want to add: ";
            cin>>amount;
            addMoney(b,amount);
            break;
        
        case 2:
            cout<<"\nENter the amount you want to withdraw: ";
            cin>>amount;
            withdraw(b,amount);
            break;

        case 3:
            checkBal(b);
            break;
        
        case 4:
            banking::getTotalBal();
            break;

        case 5:
            cout<<"\nExiting the program, GoodBye!! ";
            break;

        default:
            cout << "\nInvalid choice. Please enter a valid option.\n";
        }
    }while(choice!=5);
    
}