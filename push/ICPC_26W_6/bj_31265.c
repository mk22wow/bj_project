#include <stdio.h>
#include <string.h>

int N, M;
int list[1005];
int T[1005][1005];
int DP[1005][10005];

int main(void){
    if(scanf("%d %d", &N, &M)!=2) return 0;
    for(int i=1; i<=N; i++){
        scanf("%d", &list[i]);
    }

    for(int i=1; i<=N; i++){
        for(int j=0; j<list[i]; j++){
            scanf("%d", &T[i][j]);
        }
    }

    memset(DP, 0, sizeof(DP));
    DP[0][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=0; j<list[i]; j++){  
            int temp = T[i][j]; 
            for(int k=M-temp; k>=0; k--){
                if(DP[i-1][k] != 0 || DP[i][k] !=0){
                    DP[i][k+temp] = 1;
                }
            }   
        }
    }

    int ans = -1;
    for(int i=M; i>=0; i--){
        if(DP[N][i] == 1){
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}