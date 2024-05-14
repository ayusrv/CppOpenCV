#include "customer.h"
#include <bits/stdc++.h>
using namespace std;

customer::customer(){}
customer::customer(string customerName, long aadhar, string phoneNum)
{
    this->customerName = customerName;
    this->aadhar = aadhar;
    this->phoneNum = phoneNum;
}

void customer::setAadhar()
{
    cout << "Enter Your Aadhar Number: ";
    cin >> aadhar;
}

void customer::setPhone()
{
    cout << "Enter Your Phone Number: ";
    cin >> phoneNum;
}

// char* customer::getCustomerName(){
//     return customerName;
// }

long customer::getAadhar()
{
    return aadhar;
}

string customer::getPhoneNum()
{
    return phoneNum;
}


void customer::accept()
{
    // string ch;
    cout << "Enter Your Name: ";
    cin >> customerName;
    cout<<"Enter Your Aadhar: ";
    cin>>aadhar;
    cout<<"Enter Your Phone Number: ";
    cin>>phoneNum;
}

ostream &operator<<(ostream &out, customer &cc)
{
    out << "Name: " << cc.customerName << endl;
    out << "Aadhar Card: " << cc.aadhar << endl;
    return out;
}

customer::~customer(){
    cout<<"Destructor Called"<<endl;
}