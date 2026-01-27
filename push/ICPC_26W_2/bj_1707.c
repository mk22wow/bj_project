#include <stdio.h>
#include <stdlib.h>

int K;
int V, E;

typedef struct Edge {
   int destination;
   struct Edge* next;
}Edge;

typedef struct Vertice{
   int n;
    int color;
   Edge* E_list;
}Vertice;

typedef struct {
   int vertices;
   Vertice* V_list;
}Graph;

Graph* createGraph() {
   Graph* newG = (Graph*)malloc(sizeof(Graph));
   newG->vertices = V;
   newG->V_list = (Vertice*)malloc(sizeof(Vertice) * (V+1));
   for (int i = 1; i <= V; i++) {
    newG->V_list[i].n = i;  
    newG->V_list[i].color = -1;
    newG->V_list[i].E_list = NULL;
   }
   return newG;
}

void insertEdge(Graph* G, int a, int b){    
    Edge* newE = (Edge*)malloc(sizeof(Edge));
    newE->destination = b;
    newE->next = G->V_list[a].E_list;
    G->V_list[a].E_list = newE;
}

int Find(Graph* G, int s){
    int list[V+1];
    int front = 0, rear = 0;
    list[rear++] = s;
    while(front<rear){
        int curr_i = list[front++];
        int curr_c = G->V_list[curr_i].color;
        
        Edge* curr_E = G->V_list[curr_i].E_list;
        while(curr_E!=NULL){
            if(G->V_list[curr_E->destination].color == curr_c){
                return 1;
            }
            else if(G->V_list[curr_E->destination].color == -1){
                if(curr_c == 1){
                    G->V_list[curr_E->destination].color = 0;
                }
                else G->V_list[curr_E->destination].color = 1;
                list[rear++] = curr_E->destination;
            }
            curr_E = curr_E->next;
        }
    }
    return 0;
}

int main(void) {
   scanf("%d", &K);
   while (K--) {
      scanf("%d %d", &V, &E);
      Graph* G = createGraph();
      for (int i = 0; i < E; i++) {
         int a, b;
         scanf("%d %d", &a, &b);
         insertEdge(G, a, b);
         insertEdge(G, b, a);
      }
      int pass = 1;
      for(int i=1; i<=V; i++){
        if(G->V_list[i].color == -1){
            G->V_list[i].color = 0;
        }
        if(Find(G, i)){
            printf("NO\n");
            pass = 0;
            break;
        }
      }
      if(pass){
        printf("YES\n");
      }
      for(int i=1; i<=V; i++){
        Edge* temp = G->V_list[i].E_list;
        while(temp!=NULL){
            Edge* curr = temp->next;
            free(temp);
            temp = curr;
        }
      }
      free(G->V_list);
      free(G);
    }
}

// c++ 예시 코드
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int K; cin >> K;
//     while (K--) {
//         int V, E; cin >> V >> E;
//         vector<vector<int>> g(V);
//         while (E--) {
//             int u, v; cin >> u >> v;
//             g[--u].push_back(--v);
//             g[v].push_back(u);
//         }
//         bool ans = true;
//         vector<int> color(V, 0);
//         for (int i = 0; i < V; i++) {
//             if (!color[i]) {
//                 if (!ans) break;
//                 color[i] = 1;
//                 queue<int> q;
//                 q.push(i);
//                 while (!q.empty()) {
//                     int cur = q.front(); q.pop();
//                     for (int nxt : g[cur]) {
//                         if (!color[nxt]) {
//                             color[nxt] = 3 - color[cur];
//                             q.push(nxt);
//                         } else if (color[nxt] == color[cur]) {
//                             ans = false;
//                             while (!q.empty()) q.pop();
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//         if (ans) cout << "YES\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }
