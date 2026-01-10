#include <stdio.h>
#include <string.h>

char str[3003];
char Max[3003];
int len;

void FindMax(){
    int index = 0;
    for(int i=0; i<len; i++){
        if(str[i] == 'M' && i == len-1){
            while(index<=i){
                Max[index++] = '1';
            }
        }
        else if(str[i] == 'K'){
            Max[index++] = '5';
            while(index<=i){
                Max[index++] = '0';
            }
        }
    }
    Max[index] = '\0';
}

void FindMin(char Min[]){
    int index = 0;
    for(int i=0; i<len; i++){
        if(str[i] == 'K'){
            if(index!=i){
                Min[index++] = '1';
                while(index<i){
                    Min[index++] = '0';
                }
            }
            Min[index++] = '5';
        }
        else if(str[i] == 'M' && i == len-1){
            Min[index++] = '1';
            while(index<=i){
                Min[index++] = '0';
            }
        }

    }
    Min[index] = '\0';
}

int main(void){
    scanf("%s", str);
    len = strlen(str);
    FindMax();
    char Min[3003];
    FindMin(Min);

    printf("%s\n%s", Max, Min);
    return 0;
}