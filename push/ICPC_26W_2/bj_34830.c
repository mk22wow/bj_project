#include <stdio.h>

int main(void){
    long long N;
    long long count = 0;
    if(scanf("%lld", &N) != 1) return 0;
    if(N%2 != 0){
        count = N*(N-1) / 2;
        printf("%lld\n", count);
    }
    else{
        count = N*(N-1) / 2;
        count += (N-2) / 2;
        printf("%lld\n", count); 
    }
    return 0;
}