#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int N, K;
int list[MAX];
int distance[MAX];

int Compare(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

int main(void){
    scanf("%d %d", &N, &K);
    if(K>=N){
        printf("0\n");
        return 0;
    }
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }
    qsort(list, N, sizeof(int), Compare);
    
    int total_distance = 0;
    for(int i=0; i<N-1; i++){
        distance[i] = list[i] - list[i+1];
        total_distance += distance[i];
    }

    qsort(distance, N-1, sizeof(int), Compare);
    for(int i=0; i<K-1; i++){
        total_distance -= distance[i];
    }

    printf("%d\n", total_distance);
    return 0;
}