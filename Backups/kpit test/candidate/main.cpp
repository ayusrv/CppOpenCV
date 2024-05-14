#include "candidate.cpp"
#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

int main()
{
    candidate c[3];
    for (int i = 0; i < 3; i++)
    {
        c[i].accept();
    }

    for (int i = 0; i < 3; i++)
    {
        cout << c[i];
    }
}