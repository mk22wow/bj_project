#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100000

int N;
int list[MAX];
int value[MAX];
int max;

int Find_l(int s){
    int current =  INT_MAX;
    for(int i=N-2; i>s; i--){
        int temp = list[N-1] - list[i-1] + value[i];
        if(temp<current) current = temp;
    }
    return list[N-1]*2 - value[N-1] - current;
}

int Find_r(int s){
    int current = INT_MAX;
    for(int i=1; i<N-1; i++){
        int temp = list[i] + value[i];
        if(temp<current) current = temp;
    }
    return list[N-1]*2 - value[0] - current;
}

int main(void){
    scanf("%d", &N);
    int value_max = INT_MIN;
    for(int i=0; i<N; i++){
        scanf("%d", &value[i]);
        if(i == 0){
            list[i] = value[i];
            continue;
        }
        list[i] = value[i] + list[i-1];
        if(i!=N-1 && value[i]>value_max){
            value_max = value[i];
        }
    }

    max = list[N-1] - value[N-1] - value[0] + value_max;

    int left_max = Find_l(0);
    int right_max = Find_r(N-1);

    if(max<left_max) max = left_max;
    if(max<right_max) max = right_max;

    printf("%d\n", max);
    return 0;
}