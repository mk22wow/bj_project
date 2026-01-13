#include <stdio.h>
#include <string.h>

char str1[1000001];
char str2[37];
char stack[1000001];

int main(void){
    scanf("%s", str1);
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int index = 0;
    for(int i=0; i<len1; i++){
        int pass = 1;
        stack[index++] = str1[i];
        if(index>=len2){
            for(int j=0; j<len2; j++){
                if(stack[index-len2+j] != str2[j]){
                    pass = 0;
                    break;
                }
            }
            if(pass) index -= len2;
        }
    }
    stack[index] = '\0';

    if(index == 0){
        printf("FRULA\n");
    }
    else printf("%s\n", stack);
    return 0;
}