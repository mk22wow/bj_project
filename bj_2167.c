#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10000

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    int** list = (int**)malloc(sizeof(int*)*N);
    for(int i=0; i<N; i++){
        list[i] = (int*)malloc(sizeof(int)*M);
        for(int j=0; j<M; j++){
            int temp;
            scanf("%d", &temp);
            if(abs(temp)>10000){
                for(int k=0; k<=i; k++){
                    free(list[i]);
                }
                free(list);
                return 0;
            }
            list[i][j] = temp;
        }
    }

    int time, num = 0;
    scanf("%d", &time);
    while(num<time){
        int a, b, x, y;
        long long result = 0;
        scanf("%d %d %d %d", &a,&b,&x,&y);
        for(int i=a-1;i<x;i++){
            for(int j=b-1;j<y;j++){
                result += list[i][j];
            }
        }
        printf("%lld\n", result);
        num++;
    }
    for(int i=0; i<N; i++){
        free(list[i]);
    }
    free(list);
    return 0;
}