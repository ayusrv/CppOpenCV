//Calculate the bill and budget and display the total amount

#include<bits/stdc++.h>
using namespace std;

class billAndBudget{
    int sanctionLoad;
    int electricityslab;
    long presentReading;
    long previousReading;
    long consumption;

    public:

    //Default constructor
    billAndBudget(){
        sanctionLoad=0;
        electricityslab=0;
        presentReading=0;
        previousReading=0;
        consumption=0;
    }

    //setter for sanction load
    void setSanctionLoad(int sanctionLoad){
        this->sanctionLoad=sanctionLoad;
    }

    //setter for set electricity
    void setElectricityslab(int electricityslab){
        this->electricityslab=electricityslab;
    }

    //setter for present reading
    void setPresentReading(long presentReading){
        this->presentReading=presentReading;
    }

    //setter for previous reading
    void setPreviousReading(long previousReading){
        this->previousReading=previousReading;
    }

    //setter for consumtion
    void setConsumption(long consumption){
        this->consumption=consumption;
    }

    //getter for sanction load
    int getSanctionLoad(){
        return sanctionLoad;
    }

    //Getter for electricity slab
    int getElectricityslab(){
        return electricityslab;
    }

    //getter for Present Reading
    long getPresentReading(){
        return presentReading;
    }

    //getter for Previos Reading
    long getPreviousReading(){
        return previousReading;
    }

    //getter for Consumption
    long getConsumption(){
        return consumption;
    }

    //calculateElectricityBill to calculate the values
    float calculateElectricityBill(){
        if(previousReading>presentReading) return 0;
        else
            return (sanctionLoad*electricityslab) + (consumption*(electricityslab)/100);
    }

    //Accept values
    void accept(int sanctionLoad, int electricityslab, long presentReading, long previousReading, long consumption){
        setSanctionLoad(sanctionLoad);
        setElectricityslab(electricityslab);
        setPresentReading(presentReading);
        setPreviousReading(previousReading);
        setConsumption(consumption);
    }

    //Display FUnction
    void display(){
        cout<<"\nHere all the details of your Bills";
        cout<<"\nSanction Load: \t"<<sanctionLoad;
        cout<<"\nElectricity Slab: \t"<<electricityslab;
        cout<<"\nPresent Reading: \t"<<presentReading;
        cout<<"\nPrevious Reading: \t"<<previousReading;
        cout<<"\nTotal Consumption: \t"<<consumption;
    }
};

int main(){
    billAndBudget b;
    int sanctionLoad, electricityslab;
    long presentReading, previousReading, consumption;

    //Taking input of all the data
    cout<<"Enter the details of your reading: \n";
    cout<<"Please enter the value of Sanction Load: ";
    cin>>sanctionLoad;
    cout<<"Please enter the value of Electricity Slab: ";
    cin>>electricityslab;
    cout<<"Please enter the value of Present Reading: ";
    cin>>presentReading;
    cout<<"Please enter the value of Previous Reading: ";
    cin>>previousReading;
    cout<<"Please enter the consumptions: ";
    cin>>consumption;

    //proving the values through the set Function
    b.setSanctionLoad(sanctionLoad);
    b.setElectricityslab(electricityslab);
    b.setPresentReading(presentReading);
    b.setPreviousReading(previousReading);
    b.setConsumption(consumption);

    //To accept the details from the user and send all the details in the accept
    b.accept(sanctionLoad,electricityslab,presentReading,previousReading,consumption);

    cout<<"\nThe value of Sanction Load: "<<b.getSanctionLoad();
    cout<<"\nThe value of Electricity Slab: "<<b.getElectricityslab();
    cout<<"\nThe value of Present Reading: "<<b.getPresentReading();
    cout<<"\nThe value of Previous Reading: "<<b.getPreviousReading();
    cout<<"\nThe consumptions: "<<b.getConsumption()<<endl;

    //Calling the total bill function which calcultes the total bill
    cout<<"\n\t\t\t\tTotal Electric Bill: "<<b.calculateElectricityBill()<<endl;

    //displaying the values
    b.display();
}