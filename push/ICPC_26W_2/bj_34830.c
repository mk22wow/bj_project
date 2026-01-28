#include <stdio.h>

int result[200002];

int main(void){
    int N;
    int count = 0;
    if(scanf("%d", &N) != 1) return 0;
    if(N%2 != 0){
        count = N*(N-1) / 2;
        printf("%d\n", count);
    }
    else{
        count = N*(N-1) / 2;
        count += (N-2) / 2;
        printf("%d\n", count); 
    }
    return 0;
}