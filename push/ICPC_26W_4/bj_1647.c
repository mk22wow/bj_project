#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXM 1000005

typedef struct{
    int u;
    int v;
    int w;
}Edge;

int N, M, count = 0, answer = 0;
Edge E[MAXM];
int parent[MAXN];
int rank[MAXN];

int Compare(const void* a, const void* b){
    Edge* pa = (Edge*)a;
    Edge* pb = (Edge*)b;
    return pa->w - pb->w; 
}

int Find(int i){
    if(parent[i] == i) return i;
    return parent[i] = Find(parent[i]);
}

void Union(int a, int b, int c){
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
    answer+=c;
    count++;
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        parent[i] = i;
        rank[i] = 1;
    }
    for(int i=0; i<M; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        E[i] = (Edge){a-1,b-1,c};
    }

    qsort(E, M, sizeof(Edge), Compare);

    for(int i=0; i<M; i++){
        if(count == N-2) break;
        Edge temp = E[i];
        Union(temp.u, temp.v, temp.w);
    }

    printf("%d\n", answer);
    return 0;
}
