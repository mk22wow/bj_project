#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int N;
long long list[10000];
long long M = LLONG_MIN;

int Compare(const void* a, const void* b){
    if(*(long long*)a<*(long long*)b){
        return -1;
    }
    else return 1;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%lld", &list[i]);
    }
    

    qsort(list, N, sizeof(long long), Compare);
    if(N%2 != 0){
        M = list[--N];
    }

    for(int i=0; i<N/2; i++){
        long long temp = list[i] + list[N-1-i];
        if(temp>M) M = temp;
    }

    printf("%lld\n", M);
    return 0;
}