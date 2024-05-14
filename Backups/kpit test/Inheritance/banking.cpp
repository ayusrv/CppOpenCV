#include <iostream>
using namespace std;

class customer
{
protected:
    string name;
    string address;
    long phone;

public:
    void setVal(string name, string address, long phone)
    {
        this->name = name;
        this->address = address;
        this->phone = phone;
    }

    string getName()
    {
        return name;
    }

    string getAddress(){return address;}
};

class account : public customer
{
protected:
    int balance;
    int acc_number;
    string type_of_account;

public:
    void setVal(string name, string address, long phone, int balance, int acc_number, string type_of_account)
    {
        customer::setVal(name, address, phone);
        this->balance = balance;
        this->acc_number = acc_number;
        this->type_of_account = type_of_account;
    }
    string getAccType(void)
    {
        return type_of_account;
    }
    int getBal(void)
    {
        return balance;
    }
    int getAccNum(void)
    {
        return acc_number;
    }
};

class cur_acct : public account
{
public:
    void checkMinBal()
    {
        if (balance < 1000)
        {
            balance -= 50;
            cout<<"balance is less than the minimum balance";
        }
        else{
            cout<<"Balance is okay no amount will be deducted";
        }
    }
    void checkBook(int bal)
    {
        if (bal > balance)
        {
            cout << "Cheque dropped balance required is more than the total balance\n";
        }
        else
        {
            balance -= bal;
            cout << "Cheque approved\n";
        }
    }
};

class sav_acct : public account
{
public:
    void withdraw(int bal)
    {
        if (account::balance < bal)
        {
            cout << "Current balance is less\n";
        }
        else
        {
            account::balance -= bal;
            cout << "AMount withdrawed\n";
            cout<<getBal();
        }
    }
};

int main()
{
    account a;
    a.setVal("AYush", "Pune", 6299017320, 10000, 1234, "saving");
    cout << a.getBal()<<endl;
    sav_acct sv;
    sv.setVal("AYush", "Pune", 6299017320, 10000, 1234, "saving");
    sv.withdraw(1000);
    cout<<"\n";
    sv.getBal();
    cout<<"\n";

    cur_acct ca;
    ca.setVal("AYush", "Pune", 6299017320, 100, 1234, "saving");
    ca.checkMinBal();
    cout<<"\n";
    cout<<ca.getBal();
}