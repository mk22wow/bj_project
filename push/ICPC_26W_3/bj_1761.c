#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXlog 17

typedef struct Edge{
    int dest;
    int weight;
    struct Edge* next;
}Edge;

Edge* T[40005] = {0};
int depth[40005] = {0};
int degree[40005] = {0};
int parent[40005][MAXlog];
int N, M;

void addEdge(int u, int v, int w){
    Edge* temp1 = (Edge*)malloc(sizeof(Edge));
    temp1->dest = v;
    temp1->weight = w;
    temp1->next = T[u];
    T[u] = temp1;
    Edge* temp2 = (Edge*)malloc(sizeof(Edge));
    temp2->dest = u;
    temp2->weight = w;
    temp2->next = T[v];
    T[v] = temp2;
}

void DFS(int start, int parnet, int dep, int deg){
    depth[start] = dep;
    degree[start] = deg;
    parent[start][0] = parnet;
    Edge* temp = T[start];
    while(temp!=NULL){
        int nxt = temp->dest;
        if(degree[nxt] == -1){
            DFS(nxt, start, dep+temp->weight, deg+1);
        }
        temp = temp->next;
    }
}

void getParent(){
    for(int i=1; i<MAXlog; i++){
        for(int j=0; j<N; j++){
            if(parent[j][i-1]!=-1){
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }
    }
}

void Find(int a, int b){
    if(degree[a]>degree[b]){
        int temp = a;
        a = b;
        b = temp;
    }
    int u = a, v = b;
    int diff = degree[v] - degree[u];
    for(int i=MAXlog-1; i>=0; i--){
        if(diff>>i&1){
            v = parent[v][i];
        }
    }

    if(u == v){
        // printf("%d %d %d %d\n", b, a, depth[b], depth[a]);
        printf("%d\n", depth[b] - depth[a]);
        return;
    }
    for(int i=MAXlog-1; i>=0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    u = parent[u][0];
    printf("%d\n", depth[b] + depth[a] - 2*depth[u]);
}

int main(void){
    scanf("%d", &N);
    for(int i=1; i<N; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u-1, v-1, w);
    }
    
    memset(degree, -1, sizeof(degree));
    memset(parent, -1, sizeof(parent));
    for(int i=0; i<N; i++){
        if(degree[i] == -1){
            DFS(i, -1, 0, 0);
        }
    }
    getParent();

    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        Find(u-1, v-1);
    }

    for(int i=0; i<N; i++){
        Edge* temp_E = T[i];
        while(temp_E != NULL){
            Edge* curr_E = temp_E->next;
            free(temp_E);
            temp_E = curr_E;
        }
    }
    return 0;
}