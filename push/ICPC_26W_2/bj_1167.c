#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int V;

typedef struct Edge{
    int dest;
    int weight;
    struct Edge* next;
}Edge;

Edge* list[100005];
int distance[100005] = {0};
int total_d = 0;

void addEdge(int s, int d, int w){
    Edge* newE = (Edge*)malloc(sizeof(Edge));
    newE->dest = d;
    newE->weight = w;
    newE->next = list[s];
    list[s] = newE;
}

void Find(int s){
    int* Q = (int*)malloc(sizeof(int)*(V+1));
    int* Visited = (int*)calloc(V+1, sizeof(int));
    int front = 0, rear = 0;
    memset(distance, 0, sizeof(int)*(V+1));
    Q[rear++] = s;
    Visited[s] = 1;
    while(front<rear){
        int index = Q[front++];
        Edge* curr = list[index];
        while(curr!=NULL){
            if(Visited[curr->dest] == 0){
                Visited[curr->dest] = 1;
                distance[curr->dest] = distance[index] + curr->weight;
                Q[rear++] = curr->dest;
            }
            curr = curr->next;
        }
    }
    free(Q);
    free(Visited);
}

int Solve(int curr, int parent){
    int Max1 = 0;
    int Max2 = 0;

    Edge* temp = list[curr];
    while(temp!=NULL){
        if(temp->dest != parent){
            int h = Solve(temp->dest, curr) + temp->weight;
            
            if(h>Max1){
                Max2 = Max1;
                Max1 = h;
            }
            else if(h>Max2) Max2 = h;
        }
        temp = temp->next;
    }

    if(Max1 + Max2 > total_d) total_d = Max1 + Max2;
    return  Max1;
}

int main(void){
    if(scanf("%d", &V) != 1) return 0;
    memset(list, 0, sizeof(Edge*)*(V+2));
    for(int i=0; i<V; i++){
        int s;
        scanf("%d", &s);
        while(1){
            int a, b;
            scanf("%d", &a);
            if(a == -1) break;
            scanf("%d", &b);
            addEdge(s-1, a-1, b);
        }
    }

    Solve(0, -1);
    printf("%d\n", total_d);
    // Find(0);
    // int Max1 = INT_MIN, start_V;
    // for(int i=0; i<V; i++){
    //     if(distance[i]>Max1){
    //         Max1 = distance[i];
    //         start_V = i;
    //     }
    // }

    // Find(start_V);
    // int Max2 = INT_MIN;
    // for(int i=0; i<V; i++){
    //     if(distance[i]>Max2){
    //         Max2 = distance[i];
    //     }
    // }

    // printf("%d\n", Max2);

    for(int i=0; i<V; i++){
        Edge* temp = list[i];
        while(temp!=NULL){
            Edge* curr = temp->next;
            free(temp);
            temp = curr;
        }
    }

    return 0;
}

// c++ 예시 코드
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<pair<int, int>>> g;

// vector<int> find_dist(int start) {
//     vector<int> ret(g.size(), -1); ret[start] = 0;
//     queue<int> q; q.push(start);
//     while (!q.empty()) {
//         int cur = q.front(); q.pop();
//         for (auto &[nxt, dist] : g[cur]) {
//             if (ret[nxt] == -1) {
//                 ret[nxt] = ret[cur] + dist;
//                 q.push(nxt);
//             }
//         }
//     }
//     return ret;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int V; cin >> V;
//     g.resize(V);
//     for (int i = 0; i < V; i++) {
//         int u; cin >> u; u--;
//         while (true) {
//             int v; cin >> v;
//             if (v == -1) break;
//             int weight; cin >> weight;
//             g[u].push_back({--v, weight});
//             g[v].push_back({u, weight});
//         }
//     }

//     vector<int> dist1 = find_dist(0);
//     auto max_it = max_element(dist1.begin(), dist1.end());
//     int v2 = max_it - dist1.begin();
//     vector<int> dist2 = find_dist(v2);
//     cout << *max_element(dist2.begin(), dist2.end());
//     return 0;
// }
