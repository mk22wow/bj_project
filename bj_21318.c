#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEVEL 1000000000

void freeInt(int* list, int*level){
    free(list);
    free(level);
}

int main(void){
    int N;
    scanf("%d", &N);
    if(N<1 || N>100000){
        return 0;
    }
    int* list = (int*)malloc(sizeof(int)*N);
    int* level = (int*)malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        if(temp<1 || temp>MAX_LEVEL){
            freeInt(list, level);
            return 0;
        }
        if(i==0){
            list[i] = 0;
        }
        else{
            if(level[i-1]>temp){
                list[i] = list[i-1]+1;
            }
            else{
                list[i] = list[i-1];
            }
        }
        level[i] = temp;
    }
    int M;
    scanf("%d", &M);
    if(M<1 || M>100000){
        freeInt(list, level);
        return 0;
    }
    for(int i=0; i<M; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        int result = list[y-1]-list[x-1];
        if(y!=1){
            if(list[y-2]> list[y-1]){
                result++;
            }
        }
        printf("%d\n", result);
    }
    freeInt(list, level);
    return 0;
}