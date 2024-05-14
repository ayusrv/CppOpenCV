#include<stdio.h>
#include<string.h>
struct employee{
    char arr[30];
    int size;
    char syb;
};

void inn(int n, char ch){
    for(int i=0;i<n;i++){
        printf("%c",ch);
    }
    printf("\n");
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n/2;j++){
            printf(" ");
        }
        printf("%c",ch);
        for(int j=0;j<n/2;j++){
            printf(" ");
        }

    printf("\n");
    }
    for(int i=0;i<n;i++){
        printf("%c",ch);
    }
}

void p(int n, char ch){
    for(int i=0;i<n;i++){
        printf("%c",ch);
    }
    printf("\n");
    for(int i=0;i<n/2-1;i++){
        for(int j=0;j<n;j++){
            if(j==0 || j==n-1) printf("%c",ch);
            else printf(" ");
        }
        printf("\n");
    }
    for(int i=0;i<n-1;i++){
        printf("%c",ch);
    }
    for(int i=n/2;i<n;i++){
        printf("%c\n",ch);
    }
}

void t(int n, char ch){
    for(int i=0;i<n;i++){
        printf("%c",ch);
    }
    printf("\n");
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n/2;j++){
            printf(" ");
        }
        printf("%c",ch);
        for(int j=0;j<n/2;j++){
            printf(" ");
        }

    printf("\n");
    }
}

void k(int n, char ch){
    int k=n;
    for(int i=0;i<n/2;i++){
        printf("%c",ch);
        for(int j=1;j<k-1;j++){
            printf(" ");
        }
        printf("%c",ch);
        printf("\n");
        k--;
    }
    for(int i=n/2;i>=0;i--){
        printf("%c",ch);
        for(int j=1;j<k-1;j++){
            printf(" ");
        }
        printf("%c",ch);
        printf("\n");
        k++;
    }

}

void getAnswer(char arr[], int n, char symb){
    int size = strlen(arr);
    for(int i=0;i<size;i++){
        if(arr[i]=='K'){
            k(n,symb);
            printf("\n");
        }
        else if(arr[i]=='P'){
            p(n,symb);
            printf("\n");
        }
        else if(arr[i]=='I'){
            inn(n,symb);
            printf("\n");
        }else if(arr[i]=='T'){
            t(n,symb);
            printf("\n");
        }
    }
}

int main(){
    char arr[30];
    fgets(arr, sizeof(arr),stdin);
    int n;
    scanf("%d",&n);
    char ch;
    scanf("%c\n",&ch);
    getAnswer(arr,n,'*');
}