#include <stdio.h>

int N, K;
int W[105];
int V[105];
int DP[100005][105] = {0};

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int main(void){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%d %d", &W[i], &V[i]);
    }

    DP[W[0]][0] = V[0];
    for(int i=1; i<N; i++){
        for(int j=0; j<=K; j++){
            DP[j][i] = DP[j][i-1];
        }
        for(int j=0; j<=K; j++){ 
            if(j == 0 || DP[j][i-1] != 0){
                if(j+W[i]<=K){
                    DP[j+W[i]][i] = max(DP[j+W[i]][i], DP[j][i-1]+V[i]);
                }
            }
        }        
    }

    int max = 0;
    for(int i=0; i<=K; i++){
        if(DP[i][N-1]>max) max = DP[i][N-1];
    }
    printf("%d\n", max);
    return 0;
}