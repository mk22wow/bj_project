#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int toInt(char input[], int len){
    int num = 0;
    for(int i=0; i<len; i++){
        int multiple = pow(10, len-1-i);
        int temp = input[i]-'0';
        num += (multiple*temp);
    }
    return num;
}

int checkP(int num){
    int len = 0, temp = num;
    while(temp!=0){
        temp/=10;
        len++;
    }
    if(len == 1){
        return 1;
    }
    for(int i=0; i<len/2; i++){
        int multiple_1 = pow(10, i+1);
        int multiple_2 = pow(10, len-i);
        int temp_1 = num%multiple_1;
        int temp_2 = num%multiple_2;
        if(temp_1/(multiple_1/10) != temp_2/(multiple_2/10)){
            return 0;
        }
    }
    return 1;
}

int checkPrime(int num){
    for(int i=2; i<num; i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    char input[999];
    scanf("%s", &input);
    int len = strlen(input);
    if(len>7 || len<1){
        return 0;
    }
    int num = toInt(input, len);
    if(num == 1){
        num++;
    }
    while(1){
        if(checkP(num)){
            if(checkPrime(num)){
                printf("%d\n", num);
                break;
            }
        }
        num++;
    }
    
    return 0;
}