#include <stdio.h>
#include <stdlib.h>

int N, result = 0;
int list[100000];

int Compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    qsort(list, N, sizeof(int), Compare);
    int e = N-1;
    for(int i=0; i<N/3; i++){
        result+=list[e--];
        result+=list[e--];
        e--;
    }

    for(int i=0; i<=e; i++){
        result+=list[i];
    }

    printf("%d\n", result);
    return 0;
}