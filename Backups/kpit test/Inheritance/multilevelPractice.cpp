#include<iostream>
using namespace std;

class ceo{
    public:
    string company;
    int stocks;
    void getVal(string name, int stocks){
        this->company=name;
        this->stocks=stocks;
    }

    virtual void putVal(void){
        cout<<"\nCompany Name: "<<company<<" Stocks price: "<<stocks;
    }
};

class manager: public ceo{
    protected:
    int projectPercent;
    public:
    void getVal(int projectPercent){
        this->projectPercent=projectPercent;
    }
    virtual void putVal(void){
        cout<<"\nCompany Name: "<<company<<" Stocks price: "<<stocks;
        cout<<"\nProject completion percentage: "<<projectPercent;
    }
};

class employee: public manager{
    string emp_name;
    int salary;
    public:
    void getVal(string company, int stocks, int projectPercent, string name, int salary){
        ceo::getVal(company,stocks);
        manager::getVal(projectPercent);
        this->emp_name=name;
        this->salary=salary;
    }
    void putVal(void){
        cout<<"\nCompany Name: "<<company<<" Stocks price: "<<stocks;
        cout<<"\nProject completion percentage: "<<projectPercent;
        cout<<"\nEmployee Name: "<<emp_name<<" Employee Salary: "<<salary;
    }
};

int main(){
    employee e;
    e.getVal("KPIT",1500,89,"AYUSH",20000);
    e.putVal();

    ceo *c,cc;
    c=&e;
    c->putVal();
    
}