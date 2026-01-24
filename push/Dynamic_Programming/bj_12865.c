#include <stdio.h>

int N, K;
int W[101];
int V[101];
int dp[101][100001] = {0};

int main(void){
    scanf("%d %d", &N, &K);
    for(int i=0; i<=N; i++){
        for(int j=0; j<=K; j++){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for(int i=0; i<N; i++){
        scanf("%d %d", &W[i], &V[i]);
        for(int j=0; j<=K; j++){
            if(dp[i][j]==-1) continue;

            if(dp[i+1][j]<dp[i][j]) dp[i+1][j] = dp[i][j];

            if(W[i]+j<=K){
                int temp_v = V[i] + dp[i][j];
                if(dp[i+1][j+W[i]]<temp_v) dp[i+1][j+W[i]] = temp_v;
            }
        }
    }

    int Max = 0;
    for(int i=0; i<=K; i++){
        if(dp[N][i]>Max) Max = dp[N][i];
    }

    printf("%d\n", Max);
    
    return 0;
}