#include <stdio.h>
#include <stdlib.h>

#define MAX 25*25

int Compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void Find(int N, int list[N][N], int i, int j, int* count, int num){
    if(i-1>=0){
        if(list[i-1][j] == 1){
            list[i-1][j] = 0;
            count[num]++;
            Find(N, list, i-1, j, count, num);
        }
    }
    if(i+1<N){
        if(list[i+1][j] == 1){
             list[i+1][j] = 0;
            count[num]++;
            Find(N, list, i+1, j, count, num);
        }
    }
    if(j-1>=0){
        if(list[i][j-1] == 1){
            list[i][j-1] = 0;
            count[num]++;
            Find(N, list, i, j-1, count, num);
        }
    }
    if(j+1<N){
        if(list[i][j+1] == 1){
             list[i][j+1] = 0;
            count[num]++;
            Find(N, list, i, j+1, count, num);
        }
    }    
}

int main(void){
    int N;
    if(scanf("%d", &N) !=1 || N<1 || N>25) return 0;
    
    int list[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &list[i][j]);
        }
    }
    int count[MAX] = {0};
    int num = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(list[i][j]==1){
                count[num++] = 1;
                list[i][j] = 0;
                Find(N, list, i, j, count, num-1);
            }
        }
    }
    qsort(count, num, sizeof(int), Compare);
    printf("%d\n", num);
    for(int i=0; i<num; i++){
        printf("%d\n", count[i]);
    }

    return 0;

}