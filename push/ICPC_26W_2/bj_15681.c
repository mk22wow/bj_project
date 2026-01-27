#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge{
    int dest;
    struct Edge* next;
}Edge;

int N, R, Q;
Edge* list[100002];

int result[100002] = {0};

void Postorder(int curr, int parent){
    result[curr] = 1;
    Edge* temp = list[curr];
    while(temp!=NULL){
        if(temp->dest != parent){
            Postorder(temp->dest, curr);
            result[curr] += result[temp->dest];
        }
        temp = temp->next;
    }
}

// int disc[100002];
// int esc[100002];
// int t = -1;

// void Preorder(int curr, int parent){
//     disc[curr] = ++t;
//     Edge* temp_E = list[curr];
//     while(temp_E!=NULL){
//         if(temp_E->dest != parent){
//             Preorder(temp_E->dest, curr);
//         }
//         temp_E = temp_E->next;
//     }
//     esc[curr] = t;
// }

int main(void){
    if(scanf("%d %d %d", &N, &R, &Q) != 3) return 0;
    memset(list, 0, sizeof(list));
    for(int i=0; i<N-1; i++){
        int a, b;
        if(scanf("%d %d", &a, &b)!=2) return 0;
        Edge* E1 = (Edge*)malloc(sizeof(Edge));
        E1->dest = b;
        E1->next = list[a];
        list[a] = E1;
        Edge* E2 = (Edge*)malloc(sizeof(Edge));
        E2->dest = a;
        E2->next = list[b];
        list[b] = E2;
    }

    Postorder(R, -1);

    for(int i=0; i<Q; i++){
        int q;
        if(scanf("%d", &q) != 1) return 0;
        printf("%d\n", result[q]);
    }
    // 전위순회를 이용한 풀이
    // Preorder(R, -1);

    // for(int i=0; i<Q; i++){
    //     int a;
    //     if(scanf("%d", &a) != 1) return 0;
    //     printf("%d\n", esc[a] - disc[a] + 1);
    // }

    for(int i=1; i<=N; i++){
        Edge* temp = list[i];
        while(temp!=NULL){
            Edge* curr = temp->next;
            free(temp);
            temp = curr;
        }
    }
    return 0;
}

// // c++ 예시 코드
// #include <bits/stdc++.h>
// using namespace std;

// int disc[200000];
// int esc[200000];
// vector<int> g[200000];
// int t = -1;

// void preorder(int cur, int parent) {
//     disc[cur] = ++t; // 나를 처리
//     for (int nxt : g[cur]) {
//         if (nxt == parent) continue;
//         preorder(nxt, cur); // 자식을 처리
//     }
//     esc[cur] = t;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     memset(disc, -1, sizeof(disc));
//     memset(esc, -1, sizeof(esc));
//     int N, R, Q;
//     cin >> N >> R >> Q;
//     R--;
//     for (int i = 0; i < N - 1; i++) {
//         int U, V;
//         cin >> U >> V;
//         g[--U].push_back(--V);
//         g[V].push_back(U);
//     }
//     preorder(R, -1);
//     while (Q--) {
//         int U; cin >> U; U--;
//         cout << esc[U] - disc[U] + 1 << '\n';
//     }
//     return 0;
// }

// c++ 예시 코드
// #include <bits/stdc++.h>
// using namespace std;

// int sz[200000];
// vector<int> g[200000];
// int t = -1;

// void postorder(int cur, int parent) {
//     for (int nxt : g[cur]) {
//         if (nxt == parent) continue;
//         postorder(nxt, cur);
//         sz[cur] += sz[nxt]; // 받아온 자식노드의 값을 이용해 현재노드의 값을 업데이트
//     }
//     // 현재노드의 값이 확정되는 시점은 여기임
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     for (auto &i : sz) i = 1;
//     int N, R, Q;
//     cin >> N >> R >> Q;
//     R--;
//     for (int i = 0; i < N - 1; i++) {
//         int U, V;
//         cin >> U >> V;
//         g[--U].push_back(--V);
//         g[V].push_back(U);
//     }
//     postorder(R, -1);
//     while (Q--) {
//         int U; cin >> U; U--;
//         cout << sz[U] << '\n';
//     }
//     return 0;
// }

