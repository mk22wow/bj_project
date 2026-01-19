#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n, k;
int coin[101];
int dp[10001];

int main(void){
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &coin[i]);
    }

    dp[0] = 0;
    for(int i=1; i<=k; i++){
        dp[i] = INT_MAX;
    }
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            if(dp[j-coin[i]] != INT_MAX){
                if(dp[j]>dp[j-coin[i]]+1) dp[j] = dp[j - coin[i]] +1;
            }
        }    
    }
    
    if(dp[k] == INT_MAX){
        printf("-1\n");
    }
    else printf("%d\n", dp[k]);
    return 0;
}