#include "Functionalities.h"

void CreateObject(Container &data) {
    Cheque *c1 = new Cheque(3000);
    CardDetails *cd1 = new CardDetails("12/12/12");
    Accounts *ac1 = new Accounts(c1, cd1, 9999979, 2000);
    std::vector<Accounts*> acc1;
    acc1.push_back(ac1);
    Customer *cu1 = new Customer("Ayush", "12/12/12", acc1, 99999);
    std::vector<Customer*> cust1;
    cust1.push_back(cu1);
    data.push_back(new BankDetails("HDFC", "PUNE", "HDFC005", cust1));

    std::vector<Customer*> cust2;
    Cheque *c2 = new Cheque(2000);
    CardDetails *cd2 = new CardDetails("12/12/09");
    Accounts *ac2 = new Accounts(c2, cd2, 9999979, 5000);
    std::vector<Accounts*> acc2;
    acc2.push_back(ac2);
    Customer *cu2 = new Customer("Rahul", "12/01/12", acc2, 99999);
    cust2.push_back(cu2);
    data.push_back(new BankDetails("ICICI", "Surat", "ICICI005", cust2));

    std::vector<Customer*> cust3;
    Cheque *c3 = new Cheque(2000);
    CardDetails *cd3 = new CardDetails("2/2/12");
    Accounts *ac3 = new Accounts(c3, cd3, 9999979, 10000);
    std::vector<Accounts*> acc3;
    acc3.push_back(ac3);
    Customer *cu3 = new Customer("ROhan", "11/11/11", acc3, 99999);
    cust3.push_back(cu3);
    data.push_back(new BankDetails("SBI", "Jamshedpur", "SBIN005", cust3));
}

void PrintObject(Container &data)
{
    for(BankDetails* b : data){
        std::cout << b->bankName()<< " " << b->bankCity()<<" "<<b->bankIfsc() << std::endl;

        for(Customer* c : b->customer()){
            std::cout<<c->name()<<" "<<c->dob()<<" "<<c->phNo()<<std::endl;

            for(Accounts* a : c->accounts()){
                std::cout<<a->accountNumber()<<std::endl;
                std::cout<<a->balance()<<std::endl;
            }
        }
    }
}

void DeleteObject(Container &data){
    for(BankDetails* b : data){
        for(Customer* c : b->customer()){

            for(Accounts* a : c->accounts()){
                delete a->cheque();
                delete a->cardDetails();
                delete a;
            }
            delete c;
        }
        delete b;
    }
}

int MinimumBalance(Container &data)
{
    int _min_bal = 1000000;
    for(BankDetails* b : data){
        for(Customer* c : b->customer()){
            for(Accounts* a : c->accounts()){
                if(_min_bal>a->balance()){
                    std::cout<<a->balance()<<std::endl;
                    _min_bal = a->balance();
                }
            }
        }
    }
    return _min_bal;
}