#include <bits/stdc++.h>
#include "student.h"

using namespace std;

int main() {
    student s;
    string a = "Ayush .";
    int b = 10;
    s.setName(a);
    s.setRollNo(b);
    s.getName();
    cout << endl;
    s.getRollNo();
    return 0;
}

//g++ main.cpp student.cpp -o my_program
//./my_program