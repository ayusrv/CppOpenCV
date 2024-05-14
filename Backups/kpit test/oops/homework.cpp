#include<bits/stdc++.h>
using namespace std;
class emp{
    public:
    int id;
    string name;
    float salary;

    emp(int id, string name, float salary){
        this->id=id;
        this->name=name;
        this->salary=salary;
    }
};

class cust{
    public:
    int id;
    int phno;
    void set(int id, int phno){
        this->id=id;
        this->phno=phno;
    }
};

class box {
public:
    static int box_count;
    int width;
    int height;
    box() : width(0), height(0) {
        box_count++;
    }
    box(int width, int height) : width(width), height(height) {
        box_count++;
    }
    ~box() {
    }
};

class employee{
    public:
    string ename;
    int empsalary;
    void set(string name, int salary){
        this->ename=name;
        this->empsalary=salary;
    }

};

class marks{
    public:
    int m1,m2,m3;
    void set(int m1, int m2, int m3){
        this->m1=m1;
        this->m2=m2;
        this->m3=m3;
    }
};

int box::box_count = 0;

int sumdig(int sum){
    int s=0;
    while(sum!=0){
        s+=sum%10;
        sum/=10;
    }
    return s;
}

int main() {
    // int n;
    // cout << "Enter the number of boxes you want: ";
    // cin >> n;
    // box* b = new box[n];
    // for (int i = 0; i < n; i++) {
    //     int w, h;
    //     cout << "Enter width: ";
    //     cin >> w;
    //     cout << "Enter Height: ";
    //     cin >> h;
    //     b[i] = box(w, h);
    // }
    // for (int i = 0; i < n; i++) {
    //     cout << "Area of the " << i + 1 << " box is: " << b[i].width * b[i].height << "\n";
    // }
    // cout << "Total box count is: " << (b[0].box_count)/2 << endl;
    // delete[] b;

    employee e[4];
    e[0].set("Ayush",30);
    e[1].set("Abhi",40);
    e[2].set("Raj",10);
    e[3].set("Suraj",50);

    int ma=0,mi=INT_MAX;
    for(int i=0;i<4;i++){
        ma=max(ma,e[i].empsalary);
        mi=min(mi,e[i].empsalary);
    }
    for(int i=0;i<4;i++){
        if(e[i].empsalary==ma){
            cout<<"Employee with maximum salary is: "<<e[i].ename<<"\n";
        }
        if(e[i].empsalary==mi){
            cout<<"EMployee with minimum salary is: "<<e[i].ename<<"\n";
        }
    }

    marks m;
    m.set(80,70,69);
    int sum=m.m1+m.m2+m.m3;
    while(sum>9){
        sum=sumdig(sum);
    }
    cout<<sum;
    return 0;
}
