#include<iostream>
using namespace std;

class prac{
    int x;
    int y;
    static int c;
    public:
    prac():x(0),y(0){}
    prac(const prac &p){
        x=p.x;
        y=p.y;
    }
    void setx(int x, int y){
        this->x=x;
        this->y=y;
    }
    int getx(){
        return this->x;
    }
    int gety(){
        return this->y;
    }
    void display();
    friend prac operator+(prac &p1, prac &p2);
    friend prac operator*(prac &p1, prac &p2);
};

int prac::c=0;

prac operator+(prac &p1, prac &p2){
    prac temp;
    temp.x=p1.x*p2.x;
    temp.y=p1.y*p2.y;
    prac::c=10;
    return temp;
}

prac operator*(prac &p1, prac &p2){
    prac temp;
    temp.x=p1.x+p2.x;
    temp.y=p1.y+p2.y;
    prac::c=20;
    return temp;
}

void prac::display(){
    cout<<"\nValue of X: "<<x;
    cout<<"\nValue of Y: "<<y;
    cout<<"\nValue of C: "<<c;
}
int main(){
    prac p1,p2;
    p1.setx(10,20);
    p2.setx(20,20);
    prac p5=p1;
    prac p3 = operator+(p5,p2);
    prac p4 = operator*(p5,p2);
    if(p3.getx()>p4.getx()){
        if(p3.gety()>p4.gety()){
            cout<<"P3 is greater in all case\n";
        }
        else{
            cout<<"P3 X is bigger and P4 Y is bigger\n";
        }
    }
    else{
        if(p4.gety()>p3.gety()){
            cout<<"P4 is greater in all case\n";
        }else{
            cout<<"P4 X is greater and P3 Y is bigger\n";
        }
    }
    p3.display();
    p4.display();
}