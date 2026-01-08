#include <stdio.h>

int N;
int list[100000];
int Max = 0;


int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    int start = 0, end = N-1;
    while(start<end){
        int min = list[start]<list[end] ? list[start]:list[end];
        int temp = (end-start-1)*min;
        if(temp>Max) Max = temp;
        
        if(list[start]<list[end]) start++;
        else end--;
    }

    printf("%d\n", Max);
    return 0;
}