#include <stdio.h>

int n, m;
int parent[1000005];
int rank[1000005] = {0};

int Find(int i){
    if(parent[i] == -1) return i;
    else{
        int x = Find(parent[i]);
        parent[i] = x;
        return x;
    }
}

void Union(int a, int b){
    int r_a = Find(a);
    int r_b = Find(b);
    if(r_a != r_b){
        if(rank[r_a] < rank[r_b]){
            parent[r_a] = r_b;
        }
        else if(rank[r_a] > rank[r_b]){
            parent[r_b] = r_a;
        }
        else{
            parent[r_b] = r_a;
            rank[r_a]++;
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=0; i<=n; i++){
        parent[i] = -1;
    }

    while(m--){
        int q, a, b;
        scanf("%d %d %d", &q, &a, &b);
        if(q == 0){
            Union(a, b);
        }
        else if(q == 1){ 
            if(Find(a) == Find(b)) printf("YES\n");
            else printf("NO\n");
        }
    }
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
//     vector<int> par; // 각 정점들의 부모를 관리하는 배열
//     vector<int> rank; // 각 정점들을 루트로 하는 트리의 rank를 관리하는 배열
//     public:
//     UnionFind(int N){
//         par.assign(N+1, -1); // 부모 배열 초기화
//         rank.assign(N+1, 0); // 랭크 배열 초기화
//     }
//     int Find(int a){
//         if(par[a]==-1) return a; // 자기 자신이 루트인 경우
//         else{ 
//             int x=Find(par[a]); // 현재 트리의 루트를 찾은 다음에
//             par[a]=x; // 자기 자신을 해당 루트의 자식으로 붙여버리고(경로 압축)
//             return x; // 부모를 반환
//         }
//     }

//     void Union(int a, int b){
//         int x=Find(a);
//         int y=Find(b);
//         if(x==y) return;
//         if(rank[x]>rank[y]) swap(x, y);
//         par[x]=y;
//         if(rank[x]==rank[y]) rank[y]++;
//     }
// };

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     int N, Q;
//     cin >> N >> Q; // 초기 집합의 개수와 쿼리의 개수를 입력 받음

//     UnionFind UF(N);

//     while(Q--){
//         int type, a, b;
//         cin >> type >> a >> b;
//         if(type==0){
//             UF.Union(a, b);
//         }
//         else{
//             if(UF.Find(a)==UF.Find(b)) cout << "YES\n";
//             else cout << "NO\n";
//         }
//     }
// }