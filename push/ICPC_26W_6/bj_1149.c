#include <stdio.h>

int N;
int Price[1005][3];
int DP[1005][3] = {0};

int min(int a, int b){
    if(a<b) return a;
    return b;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d %d", &Price[i][0], &Price[i][1], &Price[i][2]);
    }

    DP[0][0] = Price[0][0];
    DP[0][1] = Price[0][1];
    DP[0][2] = Price[0][2];
    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            if(j == 0){
                DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + Price[i][0];
            }
            else if(j == 1){
                DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + Price[i][1];
            }
            else{
                DP[i][2] = min(DP[i-1][0], DP[i-1][1]) + Price[i][2];
            }
        }
    }
    printf("%d\n", min(min(DP[N-1][0],DP[N-1][1]),DP[N-1][2]));
    return 0;
}