#include<stdio.h>

int playwidnum(unsigned int n){
    long prod=1;
    int max=0;
    int val=n;
    while(n>0){
        if(prod*(n%10)>2147483648 || prod==0) return -1;
        prod*=n%10;
        max=max<n%10?n%10:max;
        n/=10;
    }
    if(prod%2==0){
        return max*max*max;
    }else{
        int sum=0;
        while(val>0){
            sum=sum+((val%10)*(val%10));
            val/=10;
        }
        return sum;
    }
}

int main(){
    unsigned int n;
    scanf("%d",&n);
    if(n>2147483648){
        printf("%d",-1);
        return 0;
    }
    printf("%d",playwidnum(n));
    return 0;
}