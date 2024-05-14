#include <bits/stdc++.h>
using namespace std;

class excep : public exception{
    public:
        const char* what(){
            return "Bill not found!!";
        }
};

class dateExcep : public exception{
    public:
        const string what(){
            return "Entered the wrong date!!";
        }
};

class customer
{
public:
    char* customerName;
    customer();
    customer(char* customerName);
    customer(const customer &c);
    void setName(char* name)
    {
        customerName = name;
    }
    char* getName()
    {
        return customerName;
    }
    void accept()
    {
        char *patientName=new char[20];
        cout << "Enter Name :- ";
        cin>>patientName;
        customerName = patientName;
        cout<<strlen(customerName);
    }
    friend ostream &operator<<(ostream &out, const customer &c);
    ~customer();
};

customer::customer() {} 
customer::customer(char* name)
{
    customerName = name;
}
customer::customer(const customer &c)
{
    this->customerName = c.customerName;
}

ostream &operator<<(ostream &out, const customer &c)
{
    out << "Customer Name: " << c.customerName;
    return out;
}
customer::~customer() {}

class Date
{
protected:
    int d, m, y;

public:
    Date();
    Date(int d, int m, int y);
    Date(const Date &d);
    void setDate(int d);
    void setMonth(int m);
    void setYear(int y);
    int getDate();
    int getMonth();
    int getYear();
    void accept();
    friend ostream &operator<<(ostream &out, const Date &dd);
};

Date::Date()
{
    this->d = 0;
    this->m = 0;
    this->y = 0;
}

Date::Date(int d, int m, int y)
{
    this->d = d;
    this->m = m;
    this->y = y;
}

Date::Date(const Date &dd)
{
    this->d = dd.d;
    this->m = dd.m;
    this->y = dd.y;
}

void Date::setDate(int d)
{
    this->d = d;
}

void Date::setMonth(int d)
{
    this->m = d;
}

void Date::setYear(int d)
{
    this->y = d;
}

int Date::getDate()
{
    return this->d;
}

int Date::getMonth()
{
    return this->m;
}

int Date::getYear()
{
    return this->y;
}

void Date::accept()
{
    // int d, m, y;
    cout << "Enter Date: ";
    cin >> d;
    cout << "Enter Month: ";
    cin >> m;
    cout << "Enter Year: ";
    cin >> y;
    // setDate(d);
    // setMonth(m);
    // setYear(y);
}

ostream &operator<<(ostream &out, const Date &dd)
{
    out << dd.d << "/ " << dd.m << "/ " << dd.y << endl;
    return out;
}

class Bill : public customer, public Date
{
protected:
    int billNumber;
    customer c;
    Date billDate;
    int billAmount;

public:
    static int totalBill;
    Bill();
    void setBillNumber(int billNumber);
    void setCustomer(const customer &cc);
    void setBillDate(const Date &dd);
    void setBillAmount(int billAmount);
    void accept();
    int getBillNumber();
    customer getCustomer();
    int getBillAmount();
    friend ostream &operator<<(ostream &out, Bill &b);
    ~Bill();
};

int Bill::totalBill = 0;

void Bill::setBillNumber(int billNumber)
{
    this->billNumber = billNumber;
}

void Bill::setBillAmount(int billAmount)
{
    this->billAmount = billAmount;
}

int Bill::getBillNumber()
{
    return billNumber;
}

int Bill::getBillAmount()
{
    return billAmount;
}

customer Bill::getCustomer()
{
    return c;
}

Bill::Bill() {}
void Bill::setCustomer(const customer &cc)
{
    this->c = cc;
}
void Bill::setBillDate(const Date &dd)
{
    this->billDate = dd;
}
void Bill::accept()
{
    cout << "Enter Bill Number: ";
    cin >> billNumber;
    cout << "Enter Bill Amount: ";
    cin >> billAmount;
    totalBill+=billAmount;
    customer::accept();
    Date::accept();
}
ostream &operator<<(ostream &out, Bill &b)
{
    try{
        if((b.getMonth()>12 || b.getMonth()<1) || (b.getMonth()==2 
            && (b.getDate()>28 || b.getDate()<1)) || ((b.getMonth()==1 || b.getMonth()==3 
            || b.getMonth()==5 || b.getMonth()==7 || b.getMonth()==8 || b.getMonth()==10 || b.getMonth()==12) 
            && (b.getDate()>31 || b.getDate()<1)) || ((b.getMonth()==4 || b.getMonth()==6 || b.getMonth()==9 || b.getMonth()==11) 
            && (b.getDate()>30 || b.getDate()<1)))
        {
            dateExcep de;
            throw de;
            return out;
        }
        out << "Customer Name: " << b.customerName << endl;
        out << "Date: " << b.getDate() << "/" << b.getMonth() << "/" << b.getYear() << endl;
        out << "Bill Number: " << b.billNumber << endl;
        out << "Bill Amount: " << b.billAmount << endl;
    }
    catch(dateExcep de){
        out<<de.what()<<endl;
    }
    return out;
}
Bill::~Bill()
{
    cout << "Destructor" << endl;
}

int main()
{
    int n = 2;
    Bill *arr = new Bill[n];
    Bill *ptr = arr;
    for (int i = 0; i < n; i++)
    {
        ptr->accept();
        ptr++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout<<"Total Bill: "<<Bill::totalBill<<endl;

    cout<<"Enter the bill Number you want to search: ";
    int bNo;
    cin>>bNo;
    int flag=-1;
    for(int i=0;i<n;i++){
        if(arr[i].getBillNumber()==bNo){
            flag=i;
        }
    }
    try{
        if(flag==-1){
            excep ex;
            throw ex;
        }
        cout<<arr[flag];
    }
    catch(excep ex){
        cout<<ex.what()<<endl;
    }
    delete[] arr;
}