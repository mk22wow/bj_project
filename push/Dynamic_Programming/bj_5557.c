#include <stdio.h>
#include <string.h>

int N;
int list[105];
long long DP[21][105];

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    memset(DP, 0, sizeof(DP));
    DP[list[0]][0] = 1;
    for(int i=1; i<N-1; i++){
        for(int j=0; j<=20; j++){
            if(DP[j][i-1] != 0){
                if(j+list[i]>=0 && j+list[i]<=20){
                    DP[j+list[i]][i] += DP[j][i-1];
                }
                if(j-list[i]>=0 && j-list[i]<=20){
                    DP[j-list[i]][i] += DP[j][i-1];
                }
            }
        }
    }

    printf("%lld\n", DP[list[N-1]][N-2]);
}