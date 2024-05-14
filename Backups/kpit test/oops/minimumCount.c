#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>

int perfectSquare(int n,int i){
    if(i==0) return 1000;
    if(n==0) return 0;
    if(n<0) return 1000;
    int take=1+perfectSquare(n-(i*i),i);
    int ntake=perfectSquare(n,i-1);
    return take<ntake?take:ntake;
}
int main(){
    int n;
    scanf("%d",&n);
    double val = sqrt((double)n);
    printf("%d",perfectSquare(n,(int)val));
    return 0;
}