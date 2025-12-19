#include <stdio.h>
#include <stdlib.h>

#define MAX 100*100

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

void Find(int M, int N, int list[M][N], int i, int j, int result[], int num){ 
    for(int k=0; k<4; k++){
        int temp_x = i+y[k];
        int temp_y = j+x[k];
        if(temp_x>=0 && temp_x<M && temp_y>=0 && temp_y<N){
            if(list[temp_x][temp_y]==0){
                list[temp_x][temp_y]=1;
                result[num]++;
                Find(M, N, list, temp_x, temp_y, result, num);
            }
        }
    }
}

int Compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(void){
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    int list[M][N];
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            list[i][j] = 0;
        }
    }
    for(int i=0; i<K; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int j=x1; j<x2; j++){
            for(int k=(M-y2); k<(M-y1); k++){
                list[k][j] = 1;
            }
        }
    }

    int result[MAX] = {0};
    int num = 0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(list[i][j] == 0){
                result[num++] = 1;
                list[i][j] = 1;
                Find(M, N, list, i,j, result, num-1);
            }
        }
    }

    qsort(result, num, sizeof(int), Compare);
    printf("%d\n", num);
    for(int i=0; i<num; i++){
        printf("%d ", result[i]);
    }

    return 0;
}