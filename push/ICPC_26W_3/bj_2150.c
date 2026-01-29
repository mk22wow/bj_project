#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge{
    int dest;
    struct Edge* next;
}Edge;

int V, E;
Edge* G[10005];

typedef struct Node{
    int* nodes;
    int size;
    int head;
}Node;

Node list[10005];

int disc[10005];
int low[10005];
int S[10005];
int on_S[10005] = {0};
int t = -1, top =-1, count_SCC = 0;

int Compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int Compare_Node(const void* a, const void* b){
    Node* pa = (Node*)a;
    Node* pb = (Node*)b;
    return pa->head - pb->head; 
}

void addEdge(int s, int e){
    Edge* temp = (Edge*)malloc(sizeof(Edge));
    temp->dest = e;
    temp->next = G[s];
    G[s] = temp;
}

void getSCC(int s){
    disc[s] = low[s] = ++t;
    S[++top] = s;
    on_S[s] = 1;
    Edge* temp = G[s];
    while(temp!=NULL){
        int d = temp->dest;
        if(disc[d] == -1){
            getSCC(d);
            if(low[s]>low[d]) low[s] = low[d]; 
        }
        else if(on_S[d] == 1){
            if(low[s]>disc[d]) low[s] = disc[d];
        }
        temp = temp->next;
    }

    if(low[s] == disc[s]){
        int* current = (int*)malloc(sizeof(int)*V);
        int count = 0;
        while(1){
            int v = S[top--];
            on_S[v] = 0;
            current[count++] = v;
            if(s == v) break;
        }

        qsort(current, count, sizeof(int), Compare);

        Node newSCC;
        newSCC.nodes = (int*)realloc(current, count*sizeof(int));
        newSCC.size = count;
        newSCC.head = newSCC.nodes[0];
        list[count_SCC++] = newSCC;
    }
}

int main(void){
    if(scanf("%d %d", &V, &E)!=2) return 0;

    for(int i=0; i<V; i++){
        disc[i] = -1;
        G[i] = NULL;
    }

    for(int i=0; i<E; i++){
        int a, b;
        if(scanf("%d %d", &a, &b)!=2) return 0;
        addEdge(a-1, b-1);
    }

    for(int i=0; i<V; i++){
        if(disc[i] == -1) getSCC(i);
    }

    printf("%d\n", count_SCC);


    qsort(list, count_SCC, sizeof(Node), Compare_Node);
    for(int j=0; j<count_SCC; j++){
        Node temp = list[j];
        for(int i=0; i<temp.size; i++){
            printf("%d ", temp.nodes[i] + 1);
        }
        printf("-1\n");
        free(temp.nodes);
    }

    for(int i=0; i<V; i++){
        Edge* temp_E = G[i];
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

// int disc[100005];
// int low[100005];
// // 스택 포함 여부를 O(1)만에 알 수 있도록 배열을 새로 만듦
// bool on_stack[100005];
// stack<int> st;
// vector<vector<int>> g;
// vector<vector<int>> sccs;
// int t = -1;

// void getSCC(int cur) {
//     disc[cur] = low[cur] = ++t; // Case 1
//     st.push(cur);
//     on_stack[cur] = true;

//     for (int nxt : g[cur]) {
//         if (disc[nxt] == -1) { // 방문한 적 없음 -> Tree Edge
//             getSCC(nxt);
//             low[cur] = min(low[cur], low[nxt]); // Case 2
//         } else if (on_stack[nxt]) { // 방문했지만 스택에 포함 -> Back Edge
//             low[cur] = min(low[cur], disc[nxt]); // Case 3
//         }
//     }

//     // low, disc 대소 확인
//     if (low[cur] == disc[cur]) {
//         vector<int> current_scc;
//         // cur이 나올 때까지 스택에서 pop
//         while (true) {
//             int v = st.top(); st.pop();
//             on_stack[v] = false;
//             current_scc.push_back(v);
//             if (cur == v) break;
//         }
//         // 문제에서 정점 번호를 출력하라고 해서 삽입된 줄
//         sort(current_scc.begin(), current_scc.end());
//         sccs.push_back(current_scc);
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 입력
//     int V, E; cin >> V >> E;

//     memset(disc, -1, sizeof(disc));
//     g.resize(V);
//     for (int i = 0; i < E; i++) {
//         int u, v; cin >> u >> v;
//         g[--u].push_back(--v);
//     }

//     // 위 알고리즘을 이용해 SCC를 구함
//     for (int i = 0; i < V; i++) {
//         if (disc[i] == -1) {
//             getSCC(i);
//         }
//     }
//     // 마찬가지로 출력용 정렬
//     sort(sccs.begin(), sccs.end());
//     cout << sccs.size() << "\n";
//     for (auto &scc : sccs) {
//         for (int node : scc) {
//             cout << node + 1 << " ";
//         }
//         cout << "-1\n";
//     }

//     return 0;
// }
