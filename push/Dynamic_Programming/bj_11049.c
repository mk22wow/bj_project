#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct{
    int a, b;
}Matrix;

int N;
Matrix list[505];
int DP[505][505];

int main(void){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d %d", &list[i].a, &list[i].b);
    }

    memset(DP, -1, sizeof(DP));
    for(int i=1; i<=N; i++){
        DP[i][i] = 0;
    }

    for(int i=1; i<N; i++){
        for(int j=1; j<=N-i; j++){
            int Min = INT_MAX;
            for(int k=j; k<j+i; k++){
                int temp = DP[j][k] + DP[k+1][j+i] + list[j].a*list[k].b*list[j+i].b;
                if(Min>temp) Min = temp;
            }
            DP[j][j+i] = Min;
        }
    }

    printf("%d\n", DP[1][N]);
    return 0;
}