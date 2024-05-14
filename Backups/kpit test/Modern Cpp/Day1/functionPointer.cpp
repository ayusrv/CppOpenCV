#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

void printtoScreen(char *str){

}

void printtoFile(char *str){

}

void printdata(void(*ptr)(char *)){
    char data[10] = "12345";
    data[2] = '6';
    ptr(data);
}

void createFile(){
    FILE *fp = fopen("ayush.txt","w");
    if(fp){
        fprintf(fp,"AYush");
        fclose(fp);
    }
}

char* readFile(){
    FILE *fp = fopen("ayush.txt","r");
    if(fp){
        char *ch = (char *)malloc(100);
        fgets(ch,100,fp);
        fclose(fp);
        return ch;
    }
    return nullptr;
}

bool flag = true;

void NotifyUser(void (*p)()){
    while(flag){
        char *str = readFile();
        if(strstr(str, "AYush")){
            p();
        }
        free(str);
        sleep(1);
    }
}

void user(){
    cout<<"Notified";
    flag = false;
}

int main(){
    // printf("%p\n",printdata);
    // fflush(stdout);
    // printdata(printtoScreen);
    // createFile();
    // if(readFile()!=nullptr){
    //     cout<<readFile();
    // }

    NotifyUser(user);
    return 0;

}