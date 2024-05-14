// Patient Management System

#include <bits/stdc++.h>
using namespace std;

class patientManagementSystem
{
    int patientNumber;
    char *patientName;
    float temperature[3];

public:

    //Default Constructor
    patientManagementSystem()
    {
        patientNumber = 0;
        patientName = NULL;
        for (int i = 0; i < 3; i++)
        {
            temperature[i] = 0;
        }
    }

    //Parameterized Constructor
    patientManagementSystem(int patientNumber, char *patientName, float temperature[3])
    {
        this->patientNumber = patientNumber;
        this->patientName=patientName;
        for (int i = 0; i < 3; i++)
        {
            this->temperature[i] = temperature[i];
        }
    }

    // Copy Constructor
    patientManagementSystem(patientManagementSystem &other)
    {
        this->patientNumber = other.patientNumber;
        this->patientName=other.patientName;
        for (int i = 0; i < 3; i++)
        {
            this->temperature[i] = other.temperature[i];
        }
    }

    //Calculate Average Temperature
    float calculateAverageTemperature(float temperature[]){
        float average = 0;
        for(int i=0;i<3;i++){
            average += temperature[i];
        }
        return average/3;
    }

    //Operator Overloading the double equal sign where I am cheking if the two names of the patient are equal or not
    bool operator==(const patientManagementSystem& other) const {
        if(strcmp(this->patientName, other.patientName)==0) return true;
        else return false;
    }

    //Operator overloadin here I am setting the first character of the patient name as s
    void operator[](const patientManagementSystem& other) const {
        this->patientName[0] = 'S';
        cout<<this->patientName<<endl;
    }

    //Operator Overloading here I a comparing the average temperatures of two patients
    bool operator<(patientManagementSystem& other1) {
        int x=calculateAverageTemperature(temperature);
        int y=other1.calculateAverageTemperature(other1.temperature);
        if(x<y) return true;
        else return false;
    }

    //Displaying the data of the patient
    void display(){
        cout<<"Patient Name: "<<patientName<<endl;
        cout<<"Patient Number: "<<patientNumber<<endl;
        cout<<"Printing the temperatures: \n"<<endl;
        for (int i = 0; i < 3; i++)
        {
            cout<<"Temperature "<<i+1<<" "<<temperature[i]<<endl;
        }
        
    }

    //Calling the OSTREAM and making it as a frind function so that it can access the private data members
    friend ostream & operator << (ostream &out, const patientManagementSystem &c);

    // Destructor
    ~patientManagementSystem()
    {
        cout << "Destructor Called" << endl;
    }
};

//Operator Overloading for output stream
ostream & operator << (ostream &out, const patientManagementSystem &p){
    out<<"Patient Number: "<<p.patientNumber<<endl;
    out<<"Patient Name: "<<p.patientName<<endl;
    for(int i=0;i<3;i++){
        out<<"Temperature-> "<<i+1<<" "<<p.temperature[i]<<endl;
    }
    return out;
}

int main()
{
    float temperature[3];
    char *patientName=new char[20];
    int patientNumber;

    //Taking user Input
    cout << "Please enter the details of the patient: " << endl;
    cout << "Enter Patient Name: ";
    cin >> patientName;
    cout << "Enter 3 temperatures: ";
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the " << i + 1 << " Temperature: ";
        cin >> temperature[i];
    }

    //Making the first patient as parameterized constructor
    patientManagementSystem p1(patientNumber, patientName, temperature);

    //Calling the copy constructor and making patient 1 = patient 2
    patientManagementSystem p2=p1;

    //Changing input for the 3rd patient
    cout<<"Enter Patient Name 2: ";
    char *patientName2=new char[20];
    cin>>patientName2;
    patientNumber=10;
    for(int i=0;i<3;i++){
        temperature[i]=i+10;
    }

    //Again calling the parameterized constructor for the object 3
    patientManagementSystem p3(patientNumber,patientName2,temperature);

    //Checking if the name of the patient 1 and patient 2 are equal or not
    if(p1==p3) cout<<"Names are equal"<<endl;
    else cout<<"Names are not Equal"<<endl;

    //Checking the temperature of the patinet 2 and patient 3 whose average is less
    if(p2<p3) cout<<"Temperature of first object is less than the other\n";
    else cout<<"Temperature of frist object is more than the other"<<endl;

    //Displaing the data of the patient 3
    cout<<"Displaying the Patient 3 Data\n";
    p3.display();

    //Printing the average temperature of patient 3
    cout<<"Average temperature of patient 3 is: "<<p3.calculateAverageTemperature(temperature)<<endl;

    //Caliing [] operator overloading and ching the first character of the name;
    p1[p2];

    //Displaying the object using ostream
    cout<<"Displaying the Details of Patient 1:\n";
    cout<<p1;
}