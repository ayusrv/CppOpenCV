#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct freq{
    char arr[500];
    int tar;
};

void groupAnalyzer(char str[], int n, int size){
    struct freq f[n];
    int x=0;
    int i=0;
    while(i<size-n+1){
        char ch[n];
        for(int j=0;j<n;j++){
            ch[j]=str[i+j];
        }
        int cnt=0;
        int j=i+1,k=0;
        while(j<size-n+1){
            if(ch[k]==str[j]){
                while(k<n && j<size){
                    if(ch[k]!=str[j]) break;
                    k++;
                    j++;
                }
                if(k==n) cnt++;
                j--;
            }
            j++;
        }
        strcpy(f[0].arr,ch);
        f[0].tar=cnt;
        i++;
    }
    for(int i=0;i<n;i++){
        printf("Char: %s and int: %d",f[i].arr,f[i].tar);
    }
}
int main(){
    char str[500];
    fgets(str, sizeof(str),stdin);
    int n;
    scanf("%d",&n);
    int size=sizeof(str)/sizeof(str[0]);
    groupAnalyzer(str, n, size);
}