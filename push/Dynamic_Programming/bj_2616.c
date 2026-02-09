#include <stdio.h>

int N, M;
int Sum[50005] = {0};
int DP[50005][4] = {0};

int Max(int a, int b){
    if(a<b) return b;
    else return a;
}

int main(void){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        int temp;
        scanf("%d", &temp);
        Sum[i] += temp+Sum[i-1];
    }
    scanf("%d", &M);
    for(int i=1; i<4; i++){
        for(int j=M; j<=N; j++){
            DP[j][i] = Max(DP[j-1][i], DP[j-M][i-1]+(Sum[j]-Sum[j-M]));
        }
    }

    printf("%d\n", DP[N][3]);
    return 0;
}