#include <stdio.h>
#include <string.h>

int checkStr(char str[], int* count_a){
    int i=0;
    while(str[i] != '\0'){
        if(str[i] == 'a'){
            (*count_a)++;
            i++;
        }
        else if(str[i] == 'b'){
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int find_a(char str[], int count_a){
    int len = strlen(str);
    int max = 0, a = 0;
    for(int i=0; i<len; i++){
        for(int j=0; j<count_a; j++){
            if(i+j<len){
                if(str[i+j] == 'a'){
                    a++;
                }
            }
            else{
                if(str[i+j-len] == 'a'){
                    a++;
                }
            }
        }
        if(a>max){
            max = a;
        }
        a = 0;
    }
    return max;
}

int main(void){
    char str[1111];
    int count_a = 0;
    if(fgets(str, 1001, stdin) == NULL){
        printf("wrong input");
        return 0;
    }
    str[strcspn(str, "\n")] = '\0';

    if(!checkStr(str, &count_a)){
        printf("wrong input");
        return 0;
    }

    int find_max = find_a(str, count_a);
    printf("%d", count_a-find_max);
    return 0;
}