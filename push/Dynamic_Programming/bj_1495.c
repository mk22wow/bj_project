#include <stdio.h>

int N, S, M;
int list[50];
int dp[51][1001] = {0};

int main(void){
    scanf("%d %d %d", &N, &S, &M);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }
    dp[0][S]= 1;
    for(int i=0; i<N; i++){
        int pass = 1;
        for(int j=0; j<=M; j++){
            if(dp[i][j] == 1){
                if(j+list[i]>=0 && j+list[i]<=M ){
                    dp[i+1][j+list[i]] = 1;
                    pass = 0;
                }
                if(j-list[i]>=0 && j-list[i]<=M){
                    dp[i+1][j-list[i]] = 1;
                    pass = 0;
                }
            }
        }
        if(pass == 1){
            printf("-1\n");
            return 0;
        }
    }

    for(int i=M; i>=0; i--){
        if(dp[N][i] != 0){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
    

}