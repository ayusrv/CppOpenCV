#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void countchar(const char *str){
    int ans[256]={0};
    for(int i=0;str[i]!='\0';i++){
        ans[(unsigned char)str[i]]++;
    }
    printf("Characters which occured once or more then once: \n");
    for(int i=0; i<256;i++){
        if(ans[i]!=0){
            printf("%c\t%d\n",(char)i,ans[i]);
        }
    }
}

struct KeyValuePair {
    char key[50];
    int value;
};
struct KeyValuePair createPair(const char *key, int value) {
    struct KeyValuePair pair;
    strcpy(pair.key, key);
    pair.value = value;
    return pair;
}
int main() {
    struct KeyValuePair myMap[5];
    myMap[0] = createPair("one", 1);
    myMap[1] = createPair("two", 2);
    myMap[2] = createPair("three", 3);
    myMap[3] = createPair("four", 4);
    myMap[4] = createPair("five", 5);
    printf("Value for key 'three': %d\n", myMap[2].value);
    printf("Value for key 'five': %d\n", myMap[4].value);
    return 0;
}