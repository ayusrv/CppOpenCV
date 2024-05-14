#ifndef CUSTOMER
#define CUSTOMER

#include<iostream>
using namespace std;

class customer{
        string customerName;
        long aadhar;
        string phoneNum;
    public:
        customer();
        customer(string customerName, long aadhar, string phoneNum);

        void setAadhar();
        void setPhone();
        // char* getCustomerName();
        long getAadhar();
        string getPhoneNum();
        void accept();
        string getCustomerName() const { return customerName; }
        void setCustomerName(const string &customerName_) { customerName = customerName_; }
        friend ostream & operator <<(ostream &out, customer &c);
        ~customer();
};
#endif