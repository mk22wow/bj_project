#include <stdio.h>
#include <string.h>

#define MAX 20000000

int N;
int W[16][16];
int DP[16][1<<16];

int Min(int a, int b){
    if(a<b) return a;
    return b;
}

int Find(int curr, int Visited){
    if(Visited==(1<<N)-1){
        if(W[curr][0] != 0) return W[curr][0];
        return MAX;
    }

    if(DP[curr][Visited]!=-1) return DP[curr][Visited];

    DP[curr][Visited] = MAX;

    for(int i=0; i<N; i++){
        if(W[curr][i] != 0 && !(Visited&(1<<i))){
            int temp = Find(i, Visited|(1<<i));
            if(temp!=MAX){
                DP[curr][Visited] = Min(DP[curr][Visited], W[curr][i]+temp);
            }
        }
    }

    return DP[curr][Visited];
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &W[i][j]);
        }
    }

    memset(DP, -1, sizeof(DP));

    int result = Find(0, 1<<0);

    printf("%d\n", result);
    return 0;
}