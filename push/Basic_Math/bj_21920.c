#include <stdio.h>
#include <stdlib.h>

double GCD(int a, int X){
    int num1, num2;
    if(a>X){
        num1 = a;
        num2 = X;
    }
    else{
        num1 = X;
        num2 = a;
    }
    while(1){
        int r = num1%num2;
        if(r==0){
            return num2;
        }
        num1 = num2;
        num2 = r;
    }
}

void checkResult(int list[], int num, int X){
    double result = 0, count = 0;
    for(int i=0; i<num; i++){
        double temp = GCD(list[i], X);
        if(temp == 1){
            result += list[i];
            count++;
        }
    }
    printf("%f\n", result/count);
}

int main(void){
    int num;
    scanf("%d", &num);
    if(num<2 || num>500000){
        return 0;
    }
    int* list = (int*)malloc(sizeof(int)*num);
    for(int i=0; i<num; i++){
        scanf("%d ", &list[i]);
        if(list[i]<2 || list[i]>1000000){
            free(list);
            return 0;
        }
    }
    int X = 0;
    scanf("%d", &X);
    if(X<2 || X>1000000){
        free(list);
        return 0;
    }
    checkResult(list, num, X);
    free(list);
    return 0;
}