#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main(void){
    unsigned long long MAX = pow(2, 63);
    int num = 0;
    char input_1[71];
    char input_2[71];
    scanf("%s %s", input_1, input_2);
    int len_1 = strlen(input_1);
    int len_2 = strlen(input_2);
    int* list_1 = (int*)malloc(sizeof(int)*len_1);
    int* list_2 = (int*)malloc(sizeof(int)*len_2);
    int max_1 = 1, max_2 = 1;
    for(int i=0; i<len_1; i++){
        int temp;
        if(input_1[i]>='a'){
            temp = input_1[i]-'a'+10;
        }
        else{
            temp = input_1[i]-'0';
        }
        max_1 = max_1>temp ? max_1:temp;
        list_1[i] = temp;
    }
    long long* result_1 = (long long*)calloc((36-max_1),sizeof(long long));
    for(int i=max_1+1; i<=36; i++){
        int index = i-max_1-1;
        for(int j=0; j<len_1; j++){
            long long multiple = pow(i, len_1-1-j);
            result_1[index] += (multiple*list_1[j]);
        }
    }

     for(int i=0; i<len_2; i++){
        int temp;
        if(input_2[i]>='a'){
            temp = input_2[i]-'a'+10;
        }
        else{
            temp = input_2[i]-'0';
        }
        max_2 = max_2>temp ? max_2:temp;
        list_2[i] = temp;
    }
    long long* result_2 = (long long*)calloc((36-max_2),sizeof(unsigned long long));
    for(int i=max_2+1; i<=36; i++){
        int index = i-max_2-1;
        for(int j=0; j<len_2; j++){
            long long multiple = pow(i, len_2-1-j);
            result_2[index] += (multiple*list_2[j]);
        }
    }

    int count = 0, A = 0, B = 0;
    long long result = 0;
    for(int i=0; i<36-max_1; i++){
        for(int j=0; j<36-max_2; j++){
            //printf("%llu %llu\n", result_1[i], result_2[j]);
            if(result_1[i] > MAX || result_2[j]>MAX){
                continue;
            }
            if(result_1[i] == result_2[j]){
                count++;
                result = result_1[i];
                A = i+max_1+1;
                B = j+max_2+1;
            }
        }
    }

    if(count>1){
        printf("Multiple\n");
    }
    else if(count == 1 && A!=B){
        printf("%llu %d %d\n", result, A, B);
    }
    else{
        printf("Impossible\n");
    }

    free(result_1);
    free(result_2);
    free(list_1);
    free(list_2);
    return 0;
}