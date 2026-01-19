#include <stdio.h>

int n, k;
int coin[100];
int dp[10001];

int main(void){
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &coin[i]);
    }

    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j] += dp[j - coin[i]];
        }
    }
    printf("%d\n", dp[k]);
    return 0;
}