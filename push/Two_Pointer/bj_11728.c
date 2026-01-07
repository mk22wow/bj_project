#include <stdio.h>
#include <stdlib.h>

int N, M;
int list[2000000];

int Compare(const void* a, const void* b){
    return *((int*)a)-*((int*)b);
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N+M; i++){
        scanf("%d", &list[i]);
    }
    qsort(list, N+M, sizeof(int), Compare);
    for(int i=0; i<N+M; i++){
        printf("%d ", list[i]);
    }

    return 0;
}