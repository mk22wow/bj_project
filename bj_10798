#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char str[5][16];
    int list[5];
    for(int i=0; i<5; i++){
        scanf("%s", str[i]);
        list[i] = strlen(str[i]);
        for(int j=0; j<strlen(str[i]); j++){
            if(!isdigit(str[i][j]) && !isalpha(str[i][j])){
                printf("wrong input");
                return 0;
            }
        }
    }

    // if(list[0]<list[1] || list[3]>list[4]){
    //     printf("wrong input");
    //     return 0;
    // }

    int max = list[0];
    for(int i=0; i<5; i++){
        if(max<list[i]){
            max = list[i];
        }
    }

    for(int i=0; i<max; i++){
        for(int j=0; j<5; j++){
            if(i<list[j]){
                printf("%c", str[j][i]);
            }
        }
    }

}