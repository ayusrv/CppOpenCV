#include <iostream>
#include <vector>
/*
        No.         Identifier      Address     COntent     Alternate Names
        1               n1           0X99H       99          ref.argref
        2               data         0187H       10          r1,r2   
*/      

void Magic(int& argRef){

}

int main(){
    int n1 = 99;
    int& ref = n1; //Creating a reference
    Magic(n1); //Pass by referene

    //NO CONTAINER FOR REFERENCES 
    // there is no merey for the reference it does not exist
    // int& arr[] = {ref}; -> nahi banega

    int data = 10;
    int &r1 = data;
    int &r2 = r1; //Creating reference to a reference (it is simply creating alt name of the object)

}

/*
    Previously:
        A pointer when stored internally in an object 
            creates representation of a poiter(smart pointer)

        A reference stored in an object internally creates represenatation
            of reference called reference_wrapper

*/