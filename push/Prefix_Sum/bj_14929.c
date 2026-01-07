#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000000

int main(void){
    int num = 0;
    scanf("%d", &num);
    if(num<0 || num>100000){
        return 0;
    }
    long long* list = (long long*)malloc(sizeof(long long)*num);
    for(int i=0; i<num; i++){
        long long temp = 0;
        scanf("%lld", &temp);
        if(abs(temp)>MAX){
            free(list);
            return 0;
        }
        list[i] = temp;
    }

    long long result = 0;
    for(int i=0; i<num; i++){
        result += list[i];
    }
    result = pow(result, 2);
    for(int i=0; i<num; i++){
        long long temp = pow(list[i], 2);
        result -= temp;
    }
    free(list);
    printf("%lld\n", result/2);
    return 0;
}