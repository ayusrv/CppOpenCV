#include<stdio.h>
#include <iostream>
using namespace std;

int main()
{

    FILE *fp = fopen("ayush.txt","w");
    if(fp){
        fprintf(fp,"AYush");
        char c = getchar();
         printf("You entered: %c\n", c);
         cout<<c;
        fclose(fp);
    }
    // fp = fopen("ayush.txt", "r");
    // if (fp) {
    //     int ch;
    //     while ((ch = fgetc(fp)) != EOF) {
    //         cout << static_cast<char>(ch);
    //     }
    // }

    return 0;
}
