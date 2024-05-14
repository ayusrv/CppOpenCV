#include <bits/stdc++.h>
using namespace std;

class cust
{
public:
    char name[25];
    long long ph;
    void setVal(char name[], long long ph)
    {
        strcpy(this->name, name);
        this->ph = ph;
    }
    friend void display(cust &c);
};

void display(cust &c)
{
    cout << "\nCustomer Name: " << c.name << "\tCustomer Ph: " << c.ph;
    cout << "\n";
}

int main()
{
    cust *c = new cust[100];
    int i = 0;
    int choice;
    int flag;
    do
    {
        cout << "\nMenu:\n1. Add new customer\n2. Change Phone Number\n3. Search Customer\n4. Display Customer\n5. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            char name[25];
            long long ph;
            cout << "Enter your name: ";
            cin.ignore();
            cin.getline(name, sizeof(name));
            cout << "Enter you phone number: ";
            cin >> ph;
            if (ph > 9999999999)
            {
                cout << "Wrong Phone number";
            }
            else
            {
                c[i].setVal(name, ph);
            }
            i++;
            break;

        case 2:
            char na[25];
            cout << "Enter the name of the user: ";
            cin.ignore();
            cin.getline(na, sizeof(na));
            flag = 1;
            for (int j = 0; j < i; j++)
            {
                if (!flag)
                {
                    break;
                }
                if (strcmp(na, c[j].name) == 0)
                {
                    int pho;
                    cout << "Enter new Phone Number: ";
                    cin >> pho;
                    if (pho >= 9999999999)
                    {
                        cout << "Phone Number provided was wrong";
                    }
                    else
                    {
                        c[j].setVal(na, pho);
                    }
                    flag = 0;
                }
            }
            if (flag)
                cout << "\nNo user found";
            break;

        case 3:
            char naa[25];
            cout << "Enter the name of the user: ";
            cin.ignore();
            cin.getline(naa, sizeof(naa));
            flag = 1;
            for (int j = 0; j < i; j++)
            {
                if (!flag)
                    break;
                if (strcmp(naa, c[j].name) == 0)
                {
                    display(c[j]);
                    flag = 0;
                }
            }
            if (flag)
                cout << "\nNo user found";
            break;

        case 4:
            for (int j = 0; j < i; j++)
            {
                display(c[j]);
                cout << endl;
            }
            break;

        case 5:
            cout << "Thank you for updating your contact list";
            break;

        default:
            cout << "\nWrong choice";
            break;
        }
    } while (choice != 5);

    delete[] c;
}