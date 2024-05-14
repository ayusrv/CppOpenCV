#include<stdio.h>
#include<string.h>

void checkFreq(char sb[], char str[], int n, int ind, int size){
    int i=ind;
    int cnt=0;
    while(i<size-n){
        char ch[n];
        for(int j=0;j<n;j++){
            ch[j]=str[i+j];
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if(ch[i]!=sb[i]) flag=1;
        }
        if(!flag) cnt++;
        i++;
    }
    printf("%s\t%d\n",sb,cnt);
}

void getFreq(char str[], int n){
    int i=0;
    int size=strlen(str);
    int arr[26][26];
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            arr[i][j]=0;
        }
    }
    while(i<size-n){
        char ch[n];
        for(int j=0;j<n;j++){
            ch[j]=str[i+j];
        }
        if(arr[(int)ch[0]-97][(int)ch[1]-97]==0){
            checkFreq(ch, str, n, i, size);
            arr[(int)ch[0]-97][(int)ch[1]-97]=1;
        }
        i++;
    }
}
int main(){
    char str[500];
    fgets(str, sizeof(str),stdin);
    int n;
    scanf("%d",&n);
    if(n==1){
        for(int i=0;i<strlen(str);i++){
            printf("\n%c\t%d",str[i],n);
        }
        return 0;
    }
    getFreq(str,n);
}