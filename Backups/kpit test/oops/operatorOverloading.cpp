#include<iostream>
using namespace std;

class space{
    int x;
    int y;
    int z;
    public:
    void getData(int a, int b, int c);
    void display(void);
    void operator-(space &s);
    void operator++();
};

void space::getData(int a, int b, int c){
    x=a;
    y=b;
    z=c;
}
void space::display(void){
    cout<<"\nValue of A is: "<<x;
    cout<<"\nValue of B is: "<<y;
    cout<<"\nValue of C is: "<<z;
}

void space::operator-(space &s){
    s.x=-s.x;
    s.y=-s.y;
    s.z=-s.z;
}

void space::operator++(){
    x++;
    y++;
    z++;
    cout<<"\n Operator";
}

class Complex{
    float x,y;
    public:
    Complex(){}
    Complex(float x, float y){
        this->x=x;
        this->y=y;
    }
    Complex operator+(Complex c);
    void display();
};

Complex Complex::operator+(Complex c){
    Complex temp;
    x=x+c.x;
    y=y+c.y;
    return temp;
}

void Complex::display(){
    cout<<x<<" "<<y<<endl;
}

class Distance{
    private:
        int feet;
        int inches;
    public:
        Distance(){
            feet=0;
            inches=0;
        }
        Distance(int f, int i){
            feet=f;
            inches=i;
        }

        //method to display Distance
        void displayDistance(){
            cout<<"F: "<<feet<<" I: "<<inches<<endl;
        }

        //Overload < operator
        bool operator <(const Distance &d){
            if(feet<d.feet) return true;
            else if(feet==d.feet && inches<d.inches) return true;
            return false;
        }
};

class A{
    private:
        int value;
    public:
        A(){}
        A(int i){value=i;}

        //This is automatically called when && operator is used between a1 and a2
        A operator&&(const A& a){
            A obj;
            obj.value = value && a.value;
            return obj;
        }

        //method to display result
        void result(){
            if(value) cout<<"Both value is non zero"<<endl;
            else cout<<"Any on or both value is equal to zero"<<endl;
        }
};
int main(){
    space s;
    s.getData(10,20,30);
    s.display();
    s.operator-(s);
    s.display();
    s.operator++();
    s.display();

    // Complex c1(4,6.7);
    // Complex c2(5,7.3);
    // Complex c3 = c1+c2;
    // c1.display();
    // c3.display();

    // Distance D1(11,10),D2(5,11);
    // if(D1<D2){
    //     cout<<"D1 is less than D2"<<endl;
    // }
    // else{
    //     cout<<"D2 is less than D1"<<endl;
    // }

    A a(10),b(20);
    A c;
    c=a&&b;
    c.result();
}

