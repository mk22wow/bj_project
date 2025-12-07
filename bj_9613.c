#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long findGCD(int num1, int num2){
    int q = 0, r = 0;
    int a, b;
    if(num1 > num2){
        a = num1;
        b = num2;
    }
    else{
        a = num2;
        b = num1;
    }
    while(1){
        q = a/b;
        r = a%b;
        if(r == 0){
            return b;
        }
        a = b;
        b = r;
    }
}

int main(void){
    int num1, i = 0;
    scanf("%d", &num1);
    if(num1<1 || num1>100){
        return 0;
    }
    while(i<num1){
        int num2, j = 0;
        unsigned long long result = 0;
        scanf("%d", &num2);
        if(num2<=1 || num2>100){
            break;
        }
        int* list = (int*)malloc(sizeof(int)*num2);
        while(j<num2){
            scanf("%d", &list[j]);
            if(list[j]<0 || list[j]>1000000){
                free(list);
                return 0;
            }
            j++;
        }
        for(j=0; j<num2; j++){
            for(int k=j+1; k<num2; k++){
                result += findGCD(list[j], list[k]); 
            }
        }
        printf("%llu\n", result);
        free(list);
        i++;
    }
}