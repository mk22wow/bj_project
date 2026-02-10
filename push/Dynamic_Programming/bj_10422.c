#include <stdio.h>

#define Max 1000000007

int T, L;
long long DP[2505] = {0};


int main(void){
    scanf("%d", &T);
    DP[0] = 1;
    for(int i=1; i<=2500; i++){
        for(int j=0; j<i; j++){
            DP[i] += DP[j]*DP[i-1-j]%Max;
            DP[i] %= Max;
        }
    }
    while(T--){
        scanf("%d", &L);
        if(L%2 != 0) printf("0\n");
        else{
            printf("%lld\n", DP[L/2]);
        }
    }
    return 0;
}