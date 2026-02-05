#include <stdio.h>
#include <stdlib.h>

int N;
int W[1005];

int Compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &W[i]);
    }

    qsort(W, N, sizeof(int), Compare);

    int answer = 1;
    for(int i=0; i<N; i++){
        if(W[i]>answer){
            break;
        }
        answer += W[i];
    }

    printf("%d\n", answer);
    return 0;
}