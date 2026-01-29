#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 500005

typedef struct Edge{
    int dest;
    struct Edge* next;
}Edge;

typedef struct Node{
    int nodes;
    struct Node* next;
}Node;

int N, M, S, P;
Edge* G[MAXN];
Node* list[MAXN];

int disc[MAXN];
int low[MAXN];
int Stack[MAXN];
int on_S[MAXN] = {0};
int cash[MAXN];
int restaurant[MAXN] = {0};
int scc_index[MAXN];
int node_cash[MAXN];
int finish[MAXN];
int dp[MAXN];
int t = -1, top = -1, count_SCC = 0;

void addEdge(int s, int e){
    Edge* temp = (Edge*)malloc(sizeof(Edge));
    temp->dest = e;
    temp->next = G[s];
    G[s] = temp;
}

void getSCC(int s){
    disc[s] = low[s] = ++t;
    Stack[++top] = s;
    on_S[s] = 1;
    Edge* curr = G[s];
    while(curr!=NULL){
        int d = curr->dest;
        if(disc[d] == -1){
            getSCC(d);
            if(low[s]>low[d]) low[s] = low[d];
        }
        else if(on_S[d] ==1){
            if(low[s]>disc[d]) low[s] = disc[d];
        }
        curr = curr->next;
    }

    if(disc[s] == low[s]){
        while(1){
            int v = Stack[top--];
            on_S[v] = 0;
            scc_index[v] = count_SCC;

            Node* scc = (Node*)malloc(sizeof(Node));
            scc->nodes = v;
            scc->next = list[count_SCC];
            list[count_SCC] = scc;

            if(v == s) break;
        }
        count_SCC++;
    }
}

int main(void){
    if(scanf("%d %d", &N, &M) != 2) return 0;

    for(int i=0; i<N; i++){
        G[i] = NULL;
        disc[i] = -1;
        list[i] = NULL;
    }

    for(int i=0; i<M; i++){
        int a, b;
        if(scanf("%d %d", &a, &b) != 2) return 0;
        addEdge(a-1, b-1);
    }

    for(int i=0; i<N; i++){
        scanf("%d", &cash[i]);
    }

    if(scanf("%d %d", &S, &P)!=2) return 0;
    for(int i=0; i<P; i++){
        int n;
        scanf("%d", &n);
        restaurant[n-1] = 1;
    }

    for(int i=0; i<N; i++){
        if(disc[i] == -1) getSCC(i);
    }

    for(int i=0; i<count_SCC; i++){
        node_cash[i] = 0;
        finish[i] = 0;
        Node* curr = list[i];
        while(curr!=NULL){
            node_cash[i] += cash[curr->nodes];
            if(restaurant[curr->nodes] == 1) finish[i] = 1; 
            curr = curr->next;
        }
    }

    for(int i=0; i<count_SCC; i++){
        dp[i] = -1;
    }

    int start = scc_index[S-1];
    dp[start] = node_cash[start];

    for(int i= count_SCC-1; i>=0; i--){
        if(dp[i] == -1) continue;
        for(Node* c = list[i]; c!=NULL; c=c->next){
            for(Edge* e = G[c->nodes]; e!=NULL; e=e->next){
                int next_index = scc_index[e->dest];
                if(i!=next_index){
                    if(dp[next_index]<dp[i]+node_cash[next_index]) dp[next_index] = dp[i]+node_cash[next_index];
                }
            }
        }
    }

    int answer = 0;
    for(int i=0; i<count_SCC; i++){
        if(finish[i] == 1&&dp[i]!=-1){
            if(dp[i]>answer) answer = dp[i];
        }
    }
    printf("%d\n", answer);
    return 0;
}