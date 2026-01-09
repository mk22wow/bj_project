#include <stdio.h>

int N, K, count = 0;
int coin[10];

int main(void){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%d", &coin[i]);
    }

    while(K!=0){
        if(K/coin[--N]>0){
            count += K/coin[N];
            K %= coin[N];
        }
    }

    printf("%d\n", count);
    return 0;
}