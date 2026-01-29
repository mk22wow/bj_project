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

// c++ 예시 코드
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int disc[500000];
// int low[500000];
// bool on_stack[500000];
// stack<int> st;
// vector<vector<int>> g;
// vector<vector<int>> sccs;
// int t = -1;

// ll node_cash[500000];
// bool final_state[500000];
// int scc_id[500000];
// ll scc_cash[500000];
// bool scc_has_fin[500000];
// ll dp[500000];

// void getSCC(int cur) {
//     disc[cur] = low[cur] = ++t;
//     st.push(cur);
//     on_stack[cur] = true;

//     for (int nxt : g[cur]) {
//         if (disc[nxt] == -1) {
//             getSCC(nxt);
//             low[cur] = min(low[cur], low[nxt]);
//         } else if (on_stack[nxt]) {
//             low[cur] = min(low[cur], disc[nxt]);
//         }
//     }

//     if (low[cur] == disc[cur]) {
//         vector<int> current_scc;
//         while (true) {
//             int v = st.top(); st.pop();
//             on_stack[v] = false;
//             current_scc.push_back(v);
//             if (cur == v) break;
//         }
//         sort(current_scc.begin(), current_scc.end());
//         sccs.push_back(current_scc);
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 입력
//     int N, M; cin >> N >> M;
//     g.resize(N);
//     memset(disc, -1, sizeof(disc));
//     for (int i = 0; i < M; i++) {
//         int u, v; cin >> u >> v;
//         g[u - 1].push_back(v - 1);
//     }
//     for (int i = 0; i < N; i++) {
//         cin >> node_cash[i];
//     }
//     int S, P;
//     cin >> S >> P;
//     S--;
//     memset(final_state, 0, sizeof(final_state));
//     for (int i = 0; i < P; i++) {
//         int x; cin >> x;
//         final_state[x - 1] = true;
//     }
    
//     // SCC 알고리즘 돌려서 SCC 구하기
//     for (int i = 0; i < N; i++) {
//         if (disc[i] == -1) getSCC(i);
//     }
    
//     // 위상정렬 순서로 만들기 위해 뒤집음
//     reverse(sccs.begin(), sccs.end());
    
//     // 정점 a는 b번 SCC에 속한다는 mapping을 만듦
//     memset(scc_id, -1, sizeof(scc_id));
//     for (int i = 0; i < sccs.size(); i++) {
//         for (int v : sccs[i]) {
//             scc_id[v] = i;
//         }
//     }
    
//     // SCC별로 묶는 작업 (돈 총량, 종료 정점 있는지)
//     for (int i = 0; i < sccs.size(); i++) {
//         scc_cash[i] = 0;
//         scc_has_fin[i] = false;
//         for (int v : sccs[i]) {
//             scc_cash[i] += node_cash[v];
//             if (final_state[v]) {
//                 scc_has_fin[i] = true;
//             }
//         }
//     }
    
//     // DP
//     // dp[i] = -1 : i번 SCC가 도달 불가
//     for (int i = 0; i < sccs.size(); i++) dp[i] = -1;
//     int start_id = scc_id[S];
//     dp[start_id] = scc_cash[start_id];
//     for (int i = 0; i < sccs.size(); i++) {
//         if (dp[i] == -1) continue;
//         // 직접 새로운 그래프에 해당하는 2차원 벡터를 만들지는 않음
//         // 그 대신 SCC 안에 들어있는 정점에서 나가는 간선들을 확인
//         for (int u : sccs[i]) {
//             for (int v : g[u]) {
//                 int next_id = scc_id[v];
//                 if (i != next_id) {
//                     dp[next_id] = max(dp[next_id], dp[i] + scc_cash[next_id]);
//                 }
//             }
//         }
//     }
    
//     // 종료 정점이 있는 SCC만 생각해 정답 출력
//     ll ans = 0;
//     for (int i = 0; i < sccs.size(); i++) {
//         if (scc_has_fin[i]) {
//             ans = max(ans, dp[i]);
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }