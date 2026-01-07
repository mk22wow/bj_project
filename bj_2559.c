#include <stdio.h>

int N, K;
int list[100000];

int main(void){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    int Max = 0;
    for(int i=0; i<K; i++){
        Max += list[i];
    }
    int temp = Max;
    for(int i=K; i<N; i++){
        temp = temp - list[i-K] + list[i];
        if(temp>Max){
            Max = temp;
        }
    }

    printf("%d", Max);
    return 0;
}