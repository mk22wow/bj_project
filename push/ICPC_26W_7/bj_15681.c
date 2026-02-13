#include <stdio.h>
#include <stdlib.h>

int N, R, Q;
int DP[100005];
int idx[100005] = {0};
int* G[100005];
int cnt[100005] = {0};

typedef struct{
    int u, v;
}Edge;

void DFS(int v, int parent){
    DP[v] = 1;
    for(int i=0; i<idx[v]; i++){
        int curr = G[v][i];
        if(curr == parent) continue;
        DFS(curr, v);
        DP[v] += DP[curr];
    }
}

int main(void){
    scanf("%d %d %d", &N, &R, &Q);
    Edge* E = (Edge*)malloc(sizeof(Edge)*N);

    for(int i=1; i<N; i++){ 
        int a, b;
        scanf("%d %d", &a, &b);
        E[i-1] = (Edge){a, b};
        cnt[a]++;
        cnt[b]++;
    }

    for(int i=1; i<=N; i++){
        G[i] = (int*)malloc(sizeof(int)*(cnt[i]));
    }

    for(int i=1; i<N; i++){
        Edge temp = E[i-1];
        G[temp.u][idx[temp.u]++] = temp.v;
        G[temp.v][idx[temp.v]++] = temp.u;
    }

    DFS(R, -1);

    for(int i=0; i<Q; i++){
        int temp;
        scanf("%d", &temp);
        printf("%d\n", DP[temp]);
    }
    
    for(int i=0; i<=N; i++){
        free(G[i]);
    }
    free(E);
    return 0;
}