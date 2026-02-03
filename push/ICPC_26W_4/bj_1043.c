#include <stdio.h>

int N, M;
int human, liar;
int h[51] = {0};
int party[51][51];
int parent[51];
int rank[51];

int Find(int i){
    if(parent[i] == i) return i;
    return parent[i] = Find(parent[i]);
}

void Union(int a, int b){
    int root_a = Find(a);
    int root_b = Find(b);
    if(root_a == root_b) return;

    if(rank[root_a]<rank[root_b]){
        int temp = root_a;
        root_a = root_b;
        root_b = temp;
    }

    parent[root_b] = root_a;
    if(rank[root_a] == rank[root_b]) rank[root_a]++;
}

int main(void){
    if(scanf("%d %d", &N, &M) != 2) return 0;
    for(int i=0; i<N; i++){
        parent[i] = i;
        rank[i] = 1;
    }

    scanf("%d", &human);

    for(int i=0; i<human; i++){
        int a;
        scanf("%d", &a);
        if(i == 0) liar = a-1;
        else Union(liar, a-1);
    }

    for(int i=0; i<M; i++){
        int n;
        scanf("%d", &n);
        for(int j=0; j<n; j++){
            scanf("%d", &party[i][j]);
            --party[i][j];
            if(j>0){
                Union(party[i][0], party[i][j]);
            }
        }
        party[i][n] = -1;
    }

    if(human == 0) printf("%d\n", M);
    else{
        int count = 0;
        liar = Find(liar);
        for(int i=0; i<M; i++){
            int j=0, pass = 1;
            while(party[i][j] != -1){
                if(Find(party[i][j]) == liar){
                    pass = 0;
                    break;
                }
                j++;
            }
            if(pass == 1) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}