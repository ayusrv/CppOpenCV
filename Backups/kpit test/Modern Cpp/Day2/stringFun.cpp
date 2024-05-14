#include<bits/stdc++.h>
using namespace std;
int main(){
    char str[20];
    cin>>str;
    int size=0;
    for(int i=0;str[i]!='\0';i++){
        size++;
    }

    //String reverse
    for(int i=0;i<size/2;i++){
        char temp = str[i];
        str[i] = str[size-1-i];
        str[size-1-i] = temp;
    }
    std::cout<<str<<endl;



    //String Cat
    std::cout<<"ENter second string"<<endl;
    char str2[10];
    cin>>str2;
    int size2=0;
    for(int i=0;str2[i]!='\0';i++){
        size2++;
    }
    char str3[size + size2];
    int ind=0;
    for(int i=0;i<size;i++){
        str3[ind++] = str[i];
    }
    for(int i=0;i<size2;i++){
        str3[ind++] = str2[i];
    }
    str3[ind]='\0';
    std::cout<<str3<<endl;


    int count=0;
    int i=0,j=0,k=0;
    while(j<size){
        while(k<size2 && j<size && str[j]==str2[k]){
            j++;
            k++;
        }
        if(k==size2 && j<=size){
            for(int l = i+1;l<j;l++){
                str[l] = 'x';
            }
            count++;
            k=0;
            i=j;
        }else{
            i=j;
        }
        j++;
    }
    if(j<size && k==size2-1 && str[j]==str2[k]){
        count++;

    }
    std::cout<<count<<endl;

    std::cout<<str<<endl;
}