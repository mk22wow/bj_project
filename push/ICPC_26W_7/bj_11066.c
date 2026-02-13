#include <stdio.h>
#include <limits.h>
#include <string.h>

int T, K;
long long Sum[505] = {0};
long long DP[505][505] = {0};
int Knuth[505][505];

int main(void){
    scanf("%d", &T);
    while(T--){
        Sum[0] = 0;
        scanf("%d", &K);
        for(int i=0; i<=K; i++){
            DP[i][i] = 0;
            Knuth[i][i] = i; 
        }
        for(int i=1; i<=K; i++){
            scanf("%lld", &Sum[i]);
            Sum[i] += Sum[i-1];
        }

        for(int i=1; i<K; i++){
            for(int j=1; j<=K-i; j++){
                DP[j][j+i] = LLONG_MAX;
                for(int k=Knuth[j][j+i-1]; k<=Knuth[j+1][j+i]; k++){
                    if(k>=j+i) break;
                    long long temp = DP[j][k] + DP[k+1][j+i] + Sum[j+i] - Sum[j-1];
                    if(DP[j][j+i]>temp){
                        DP[j][j+i] = temp;
                        Knuth[j][j+i] = k;
                    }
                }
            }
        }

        printf("%lld\n", DP[1][K]);
    }


}