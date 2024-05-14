#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char firststr[50]="This is softwareTestingHelp.com";
    char secondstr[50]="a testing platform";
    int len=strlen(firststr);
    cout<<"Length of first string is: "<<len;
    strcpy(secondstr,"software testing");
    cout<<"\nResultant second string is: "<<secondstr;
    cout<<"\nComparing first string and second string: "<<strcmp(firststr,secondstr);
    strcat(secondstr," for you");
    cout<<"\nConcatenated String: "<<secondstr;
    cout<<"\nFirst occurance of i in firststr is: "<<strchr(firststr,'i');
    cout<<"\nFirst occurance of software in firststr is: "<<strstr(firststr,"software");
}