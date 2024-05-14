#include <iostream>
#include <cstring>
using namespace std;

class Distance
{
    int meter;
    int centimeter;

public:
    Distance()
    {
        meter = 0;
        centimeter = 0;
    }

    Distance(int meter, int centimeter)
    {
        this->meter = meter;
        this->centimeter = centimeter;
    }

    Distance(const Distance &d)
    {
        this->meter = d.meter;
        this->centimeter = d.centimeter;
    }

    void display()
    {
        cout << meter << " meter " << centimeter << " centimeter" << endl;
    }

    Distance operator+(const Distance &d)
    {
        cout << "Operator overloading function called ......" << endl;
        Distance temp; // default constructor will be invoked
        temp.meter += this->meter;
        temp.centimeter += this->centimeter;
        temp.meter += d.meter;
        temp.centimeter += d.centimeter;
        if (temp.centimeter >= 100)
        {
            temp.centimeter -= 100;
            temp.meter += 1;
        }
        cout << "Inside operator overloading function, temp =" << temp.meter << " meter " << temp.centimeter << " centimeter" << endl;
        return temp;
    }

    Distance operator+(int x)
    {
        Distance temp;
        temp.meter = this->meter;
        temp.centimeter = this->centimeter;
        temp.meter += x;
        return temp;
    }

    Distance operator++()
    {
        this->meter++;
        return *this;
    }

    Distance operator++(int x)
    {
        this->meter++;
        return *this;
    }

    friend Distance operator+(int x, Distance &d);
    friend ostream &operator<<(ostream &osr, Distance d);
    friend istream &operator>>(istream &isr, Distance &d);
};

Distance operator+(int x, Distance &d)
{
    Distance temp;
    temp.meter = d.meter;
    temp.centimeter = d.centimeter;
    temp.meter += x;
    return temp;
}

ostream &operator<<(ostream &osr, Distance d)
{
    osr << d.meter << " meter " << d.centimeter << " centimeter";
    return osr;
}

istream &operator>>(istream &isr, Distance &d)
{
    cout << endl
         << "Enter meter:";
    isr >> d.meter;
    cout << endl
         << "Enter centimeter:";
    isr >> d.centimeter;
    return isr;
}

int main()
{
    Distance d1(100, 26), d2(20, 84);
    Distance d3;

    d1.display();
    d2.display();

    d3 = d1 + d2;
    d3.display();

    Distance d4 = d3 + 5;
    d4.display();

    ++d4;
    d4.display();

    d4++;
    d4.display();

    Distance d5;
    d5 = 5 + d4;
    d5.display();

    Distance d6 = d5 + 10;
    Distance da(1, 1), db(2, 2), dc(3, 3);
    Distance dsum = da + db + dc;
    dsum.display();

    Distance dx, dy, dz;
    cin >> dx;
    cin >> dy;
    dz = dx + dy;
    cout << "----------- Displaying Distance ------------" << endl;
    cout << dz;
}