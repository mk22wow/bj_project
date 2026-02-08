#include <stdio.h>

int N, M, K;
int Candy[30005];
int parent[30005];
int count[30005];
int DP[30005][3005] = {0};

int Find(int i){
    if(parent[i] == i) return i;
    return parent[i] = Find(parent[i]);
}

void Union(int a, int b){
    int root_a = Find(a);
    int root_b = Find(b);
    if(root_a == root_b) return;

    if(count[root_a]<count[root_b]){
        int temp = root_a;
        root_a = root_b;
        root_b = temp;
    }
    parent[root_b] = root_a;
    count[root_a] += count[root_b];
    Candy[root_a] += Candy[root_b];
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int main(void){
    if(scanf("%d %d %d", &N, &M, &K) != 3) return 0;
    for(int i=0; i<N; i++){
        scanf("%d", &Candy[i]);
    }

    for(int i=0; i<N; i++){
        parent[i] = i;
        count[i] = 1;
    }

    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        Union(a-1, b-1);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            DP[i][j] = -1;
        }
    }
    DP[0][0] = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            if(DP[i][j] == -1) continue;

            if(DP[i+1][j]<DP[i][j]) DP[i+1][j] = DP[i][j];

            if(i == Find(i) && j+count[i]<K){
                DP[i+1][j+count[i]] = max(DP[i][j+count[i]], DP[i][j]+Candy[i]);
            }
        }
    }

    int max = 0;
    for(int i=0; i<K; i++){
        if(max<DP[N][i]) max = DP[N][i];
    }
    
    printf("%d\n", max);
    return 0;
}