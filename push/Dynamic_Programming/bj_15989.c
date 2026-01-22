#include <stdio.h>
#include <stdlib.h>

int T, n;
int list[3] = {1,2,3};

int main(void){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int* dp = (int*)calloc(n+1, sizeof(int));
        dp[0] = 1;
        for(int j=0; j<3; j++){
            for(int i=list[j]; i<=n; i++){
                dp[i] += dp[i-list[j]];
            }
        }
        printf("%d\n", dp[n]);
        free(dp);
    }
    return 0;
}