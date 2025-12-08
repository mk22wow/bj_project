#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    int* list = (int*)calloc(num1 ,sizeof(int));
    int sum = 0;
    for(int i=0; i<num1; i++){
        int temp = 0;
        scanf("%d", &temp);
        if(temp<0 || temp>1000){
            free(list);
            return 0;
        }
        sum += temp;
        list[i] = sum;
    }

    for(int i=0; i<num2; i++){
        int i,j;
        scanf("%d %d",&i,&j);
        int result;
        if(i>=2){
            result = list[j-1] - list[i-2];
        }
        else{
            result = list[j-1];
        }
        printf("%d\n", result);
    }
    free(list);
    return 0;
}