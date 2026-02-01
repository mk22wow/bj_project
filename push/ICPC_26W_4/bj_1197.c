#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int u;
    int v;
    int w;
}Edge;

Edge list[100005];
int parent[10005];
int rank[10005] = {0};

int V, E, count_V = 0, answer = 0;

int Compare(const void* a, const void* b){
    Edge* pa = (Edge*)a;
    Edge* pb = (Edge*)b;
    return pa->w - pb->w;
}

int Find(int i){
    if(parent[i] == -1){
        return i;
    }
    return parent[i] = Find(parent[i]);
}

void Union(int a, int b){
    int root_a = Find(a);
    int root_b = Find(b);
    if(rank[root_a]<rank[root_b]){
        int temp = root_a;
        root_a = root_b;
        root_b = temp;
    }
    parent[root_b] = root_a;
    if(rank[root_a] == rank[root_b]){
        rank[root_a]++;
    }
}

int main(void){
    scanf("%d %d", &V, &E);
    for(int i=0; i<V; i++){
        parent[i] = -1;
    }

    for(int i=0; i<E; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        list[i] = (Edge){a-1, b-1, c};
    }

    qsort(list, E, sizeof(Edge), Compare);

    for(int i=0; i<E; i++){
        Edge temp = list[i];
        if(Find(temp.u) != Find(temp.v)){
            answer += temp.w;
            Union(temp.u, temp.v);
            count_V++;
        }
        if(count_V == V-1){
            break;
        }
    }

    printf("%d\n", answer);
    return 0;
}

// c++ 예시 코드
// #include <bits/stdc++.h>
// #define int long long
// #define pii pair<int, int>
// #define all(v) v.begin(), v.end()

// using namespace std;

// class UnionFind{
//     private:
//     vector<int> par; // 각 원소들의 부모를 관리하는 배열
//     vector<int> rank; // 해당 원소를 루트로 하는 트리의 높이를 관리하는 배열

//     public:
//     UnionFind(int N){
//         par.resize(N+1);
//         for(int i=0; i<=N; i++){
//             par[i]=i; // 부모가 없음 = 부모가 자기 자신
//             // 이렇게 함으로써 루트 노드를 찾을 때, 자기 자신이 부모인 정점을 찾아서 해당 정점의 부모를 출력하면 됨
//         }
//         rank.assign(N+1, 1);
//     }
//     int find(int a){//a가 속한 트릐의 루트노드를 찾는 과정
//         return (par[a]==a) ? a : par[a] = find(par[a]); 
//         // 자신이 부모인 경우, 즉 트리의 루트인 경우 자기 자신을 그대로 반환
//         // 부모가 존재하는 경우, 부모에 find 연산을 적용
//         // 이후 반환값을 자신의 부모로 바꿈으로써 경로압축을 수행
//     }
//     void Union(int a, int b){
//         int x=find(a);
//         int y=find(b); // 각 트리의 루트노드를 찾아줌
//         if(x==y) return;
//         if(rank[x]>rank[y]) swap(x, y);
//         par[x]=y; // x를 y의 자식으로 이어줌
//         if(rank[x]==rank[y]) rank[y]++;
//     }
// };

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     int N, M;
//     cin >> N >> M; // 정점과 간선의 개수를 입력받음

//     priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> PQ; // 간선을 가중치 오름차순으로 정렬해줄 Priority Queue

//     for(int i=0; i<M; i++){
//         int a, b, c;
//         cin >> a >> b >> c;
//         PQ.push({c, a, b}); // PQ에 간선을 집어 넣음
//     }

//     UnionFind UF(N);// 정점이 같은 연결요소에 속해있는지를 확인하기 위한 UnionFind
//     int ans=0;// 가중치 총합을 담을 값
//     while(!PQ.empty()){
//         auto [weight, node1, node2] = PQ.top();
//         PQ.pop();
//         if(UF.find(node1) == UF.find(node2)) continue; // node1과 node2가 같은 연결요소일 경우 스킵
//         UF.Union(node1, node2); // node1과 node2가 다른 연결요소일 경우에 이어줌
//         ans+=weight; // 답에다가 가중치를 더하고
//     }
//     cout << ans; // 합을 출력
// }