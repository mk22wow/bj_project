#include <stdio.h>

int N;
long long Dp[100][100] = {0};

int main(void){
    scanf("%d", &N);
    Dp[0][0] = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int temp;
            scanf("%d", &temp);
            if( i!=N-1 || j!=N-1){
                if(Dp[i][j] != 0){
                    if(i+temp<N){
                        Dp[i+temp][j] += Dp[i][j];
                    }
                    if(j+temp<N){
                        Dp[i][j+temp] += Dp[i][j];
                    }
                }
            }
        }
    }
    printf("%lld\n", Dp[N-1][N-1]);
    return 0;
}