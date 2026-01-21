#include <stdio.h>

int N;
int DP[1500001] = {0};
int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int T, P;
        scanf("%d %d", &T, &P);
        if(DP[i]>DP[i+1]){
            DP[i+1] = DP[i];
        }
        if(i+T<=N && DP[i+T]<DP[i]+P){
            DP[i+T] = DP[i] + P;
        }
    }
    
    printf("%d\n", DP[N]);

    return 0;
}