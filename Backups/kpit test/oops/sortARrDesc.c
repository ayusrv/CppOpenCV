#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void solve(int ans[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int sum=0;
        if(ans[i]>999 && ans[i]<=9999){
            if(ans[i]/1000==1 || ans[i]/1000==2 || ans[i]/1000==6) sum+=3;
            else if(ans[i]/1000==4 || ans[i]/1000==5 || ans[i]/1000==9) sum+=4;
            else if(ans[i]/1000==3 || ans[i]/1000==7 || ans[i]/1000==8) sum+=5;
            ans[i]%=1000;
            sum+=8;
            // printf("%d array and %d sum\n", ans[i],sum);
        }
        if(ans[i]>99 && ans[i]<=999){
            // if(ans[i]%100==0) sum+=0;
            if(ans[i]/100==2 || ans[i]/100==6 || ans[i]/100==1) sum+=3;
            else if(ans[i]/100==4 || ans[i]/100==5 || ans[i]/100==9) sum+=4;
            else if(ans[i]/100==3 || ans[i]/100==7 || ans[i]/100==8) sum+=5;
            ans[i]%=100;
            sum+=7;
            // printf("%d array and %d sum\n", ans[i],sum);
        }
        if(ans[i]>=90 && ans[i]<=99){
            if(ans[i]%90 || ans[i]%90==2 || ans[i]%90==6) sum+=3;
            else if(ans[i]%90==4 || ans[i]%90==5 || ans[i]%90==9) sum+=4;
            else if(ans[i]%90==3 || ans[i]%90==7 || ans[i]%90==8) sum+=5;
            sum+=5;
            // ans[i]%=90;
            // printf("%d array and %d sum\n", ans[i],sum);
        }
        if(ans[i]>=80 && ans[i]<=89){
            if(ans[i]%80==1 || ans[i]%80==2 || ans[i]%80==6) sum+=3;
            else if(ans[i]%80==4 || ans[i]%80==5 || ans[i]%80==9) sum+=4;
            else if(ans[i]%80==3 || ans[i]%80==7 || ans[i]%80==8) sum+=5;
            sum+=6;
            // ans[i]%=80;
            // printf("%d array and %d sum\n", ans[i],sum);
        }
        if(ans[i]>=70 && ans[i]<=79){
            if(ans[i]%70==1 || ans[i]%70==2 || ans[i]%70==6) sum+=3;
            else if(ans[i]%70==4 || ans[i]%70==5 || ans[i]%70==9) sum+=4;
            else if(ans[i]%70==3 || ans[i]%70==7 || ans[i]%70==8) sum+=5;
            sum+=7;
            // ans[i]%=7;
            // printf("%d array and %d sum\n", ans[i],sum);
        }
        if(ans[i]>=60 && ans[i]<=69){
            if(ans[i]%60==1 || ans[i]%60==2 || ans[i]%60==6) sum+=3;
            else if(ans[i]%60==4 || ans[i]%60==5 || ans[i]%60==9) sum+=4;
            else if(ans[i]%60==3 || ans[i]%60==7 || ans[i]%60==8) sum+=5;
            sum+=5;
            // ans[i]%=60;
            // printf("%d array and %d sum\n", ans[i],sum);
        }
        if(ans[i]>=50 && ans[i]<=59){
            if(ans[i]%50==1 || ans[i]%50==2 || ans[i]%50==6) sum+=3;
            else if(ans[i]%50==4 || ans[i]%50==5 || ans[i]%50==9) sum+=4;
            else if(ans[i]%50==3 || ans[i]%50==7 || ans[i]%50==8) sum+=5;
            sum+=5;
            // ans[i]%=50;
            // printf("%d array and %d sum\n", ans[i],sum);

        }
        if(ans[i]>=40 && ans[i]<=49){
            if(ans[i]%40==1 || ans[i]%40==2 || ans[i]%40==6) sum+=3;
            else if(ans[i]%40==4 || ans[i]%40==5 || ans[i]%40==9) sum+=4;
            else if(ans[i]%40==3 || ans[i]%40==7 || ans[i]%40==8) sum+=5;
            sum+=5;
            // ans[i]%=40;
            // printf("%d array and %d sum\n", ans[i],sum);
        }
        if(ans[i]>=30 && ans[i]<=39){
            if(ans[i]%30==1 || ans[i]%30==2 || ans[i]%30==6) sum+=3;
            else if(ans[i]%30==4 || ans[i]%30==5 || ans[i]%30==9) sum+=4;
            else if(ans[i]%30==3 || ans[i]%30==7 || ans[i]%30==8) sum+=5;
            sum+=6;
            // printf("%d array and %d sum\n", ans[i],sum);
        }
        if(ans[i]>=20 && ans[i]<=29){
            if(ans[i]%20==1 || ans[i]%20==2 || ans[i]%20==6) sum+=3;
            else if(ans[i]%20==4 || ans[i]%20==5 || ans[i]%20==9) sum+=4;
            else if(ans[i]%20==3 || ans[i]%20==7 || ans[i]%20==8) sum+=5;
            sum+=6;
            // printf("%d array and %d sum\n", ans[i],sum);
        }
        if(ans[i]==11 || ans[i]==12) sum+=6;
        if(ans[i]==13 || ans[i]==14 || ans[i]==18 || ans[i]==19) sum+=8;
        if(ans[i]==15 || ans[i]==16) sum+=7;
        if(ans[i]==17) sum+=9;
        if(ans[i]==1 || ans[i]==2 || ans[i]==6 || ans[i]==10) sum+=3;
        if(ans[i]==4 || ans[i]==5 || ans[i]==9) sum+=4;
        if(ans[i]==3 || ans[i]==7 || ans[i]==8) sum+=5;
        if(sum==0 && ans[i]==0) sum+=4;
        ans[i] = sum;
    }

    // for(int i=0;i<n-1;i++){
    //     printf("%d ",ans[i]);
    // }
    qsort(ans, n-1, sizeof(int), compare);
    for(int i=0;i<(n-1)/2;i++){
        int temp = ans[i];
        ans[i]=ans[n-i-2];
        ans[n-2-i]=temp;
    }
    printf("\n%d ",ans[0]);
    for(int i=1;i<n-1;i++){
        if(ans[i]==ans[i-1]) continue;
        else printf("%d ",ans[i]);
    }
}
void sortArrDesc(int arr[], int n){
    int ans[n-1];
    for(int i=0;i<n-1;i++){
        ans[i] = abs(arr[i]-arr[i+1]);
    }
    int flag=0;
    int val=ans[0];
    for(int i=1;i<n-1;i++){
        if(val!=ans[i]) flag=1;
    }
    solve(ans,n);
    
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sortArrDesc(arr,n);
}