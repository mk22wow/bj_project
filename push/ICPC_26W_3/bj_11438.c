#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

typedef struct Edge{
    int dest;
    struct Edge* next;
}Edge;

int N, M, log;
Edge* T[MAXN] = {0};
int depth[MAXN];
int parent[MAXN][20];

void addEdge(int a, int b){
    Edge* temp1 = (Edge*)malloc(sizeof(Edge));
    temp1->dest = b;
    temp1->next = T[a];
    T[a] = temp1;
    Edge* temp2 = (Edge*)malloc(sizeof(Edge));
    temp2->dest = a;
    temp2->next = T[b];
    T[b] = temp2;
}

int LOG(){
    int log = 0, temp = N;
    while((temp/2)>0){
        temp/=2;
        log++;
    }
    return log;

}
void DFS(int s, int p, int d){
    depth[s] = d;
    parent[s][0] = p;
    Edge* temp = T[s];
    while(temp!=NULL){
        if(temp->dest != p){
            DFS(temp->dest, s, d+1);
        }
        temp = temp->next;
    }
}

void DP(){
    for(int i=1; i<=log; i++){
        for(int j=0; j<N; j++){
            if(parent[j][i-1] != -1){
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }
    }
}

void Find(int a, int b){
    if(depth[a]>depth[b]){
        int temp = a;
        a = b;
        b = temp;
    }
    int diff = depth[b] - depth[a];

    for(int i=0; diff>0; i++){
        if(diff&1) b = parent[b][i];
        diff>>=1;
    }

    if(a == b) printf("%d\n", a+1);
    else{
        for(int i=log; i>=0; i--){
            if(parent[a][i] != parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        printf("%d\n", parent[a][0]+1);
    }
    return;
}

int main(void){
    scanf("%d", &N); 
    for(int i=0; i<N-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a-1, b-1);
    }

    log = LOG();
    memset(parent, -1, sizeof(parent));
    DFS(0, -1, 0);
    DP();

    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        Find(a-1, b-1);
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

// c++ 예시 코드
// #include <bits/stdc++.h>
// using namespace std;

// // depth[v]: v에서 루트까지 거리
// int depth[100000];
// // parent[i][j]: j번 정점의 (2의 i제곱)번 부모
// // PPT랑 순서를 뒤집어놨네요;;;
// int parent[18][100000];
// vector<int> g[100000];

// // cur: 현재정점, p: 부모정점, d: 현재깊이
// void dfs(int cur, int p, int d) {
//     // depth, parent[0][...]만 업데이트
//     depth[cur] = d;
//     parent[0][cur] = p;
//     for (int nxt : g[cur]) {
//         if (nxt != p) {
//             // 다음 노드에 부모 정보를 파라미터로 전달
//             dfs(nxt, cur, d + 1);
//         }
//     }
// }

// void preprocess(int N, int root) {
//     memset(parent, -1, sizeof(parent));
//     dfs(root, -1, 0);

//     // sparse table 전처리 O(VlogV)
//     // 2의 (k-1)제곱번 부모의 2의 (k-1)제곱번 부모는 2의 k제곱번 부모
//     for (int k = 1; k < 18; k++) {
//         for (int i = 0; i < N; i++) {
//             if (parent[k - 1][i] != -1) {
//                 parent[k][i] = parent[k - 1][parent[k - 1][i]];
//             }
//         }
//     }
// }

// int query(int u, int v) {
//     // without loss of generality
//     if (depth[u] < depth[v]) swap(u, v);
    
//     // 더 깊이 있는 정점을 덜 깊은 정점까지 부모를 타고 올려줌
//     int diff = depth[u] - depth[v];
//     for (int i = 0; diff > 0; i++) {
//         if (diff & 1) u = parent[i][u];
//         diff >>= 1;
//     }
    
//     // 만약에 여기서 같으면 LCA(u, v) = u
//     if (u == v) return u;
    
//     // 2의 17제곱부터 지수를 내려가면서 LCA 탐색
//     for (int k = 17; k >= 0; k--) {
//         if (parent[k][u] != parent[k][v]) {
//             u = parent[k][u];
//             v = parent[k][v];
//         }
//     }
//     return parent[0][u];
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 입력
//     int N; cin >> N;
//     for (int i = 0; i < N - 1; i++) {
//         int u, v;
//         cin >> u >> v;
//         g[--u].push_back(--v);
//         g[v].push_back(u);
//     }
    
//     // sparse table 구성, 쿼리 처리 등을 모두 위에서 함
//     // 여기서는 함수를 부르기만
//     preprocess(N, 0);
//     int M;
//     cin >> M;
//     while (M--) {
//         int u, v;
//         cin >> u >> v;
//         cout << query(u - 1, v - 1) + 1 << "\n";
//     }
//     return 0;
// }