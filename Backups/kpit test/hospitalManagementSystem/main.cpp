#include "employee.cpp"
#include "ayurveda.cpp"
#include "neurologist.cpp"
#include "orthopadic.cpp"
#include <bits/stdc++.h>
using namespace std;

class TimeExcep : public exception
{
public:
    const char *what()
    {
        return "Your time is less thhan 9 hours";
    }
};

int main()
{
    employee *arr[3];
    for (int i = 0; i < 3; i++)
    {
        int id, timeIn, timeOut;
        char *name = new char[20];
        cout << "Enter Employee Id: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter time in: ";
        cin >> timeIn;
        cout << "Enter time out: ";
        cin >> timeOut;
        cout << "Enter your department-> Ayurveda, Neurologist, Orthopadic: ";
        string dep;
        cin >> dep;
        employee *ptr;
            if (dep == "Orthopadic")
            {
                ptr = new orthopadic(id, timeIn, timeOut, name, 200);
            }
            else if (dep == "Neurologist")
            {
                ptr = new neurologist(id, timeIn, timeOut, name, 250);
            }
            else
            {
                ptr = new ayurveda(id, timeIn, timeOut, name, 150);
            }
            arr[i] = ptr;
    }
    for (int i = 0; i < 3; i++)
    {
        try
        {
            if ((arr[i]->timeOut - arr[i]->timeIn) < 900)
            {
                TimeExcep te;
                throw te;
            }
            arr[i]->display();
            arr[i]->salary();
        }

        catch(TimeExcep ex){
            arr[i] -> display();
            cout<<ex.what()<<endl;
        }
    }
}