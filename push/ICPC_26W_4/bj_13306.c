#include <stdio.h>

#define MAXN 200005

typedef struct {
	int q;
	int n1;
	int n2;
}Quest;

int N, Q;
int Tree[MAXN];
int temp_p[MAXN];
int parent[MAXN];
int rank[MAXN];
Quest temp_Q[MAXN*2];
int answer[MAXN], index = 0;

int Find(int i) {
	if (parent[i] == i) return i;
	return parent[i] = Find(parent[i]);
}

void Union(int a, int b) {
	int root_a = Find(a);
	int root_b = Find(b);
	if (rank[root_a] < rank[root_b]) {
		int temp = root_a;
		root_a = root_b;
		root_b = temp;
	}

	parent[root_b] = root_a;
	if (rank[root_a] == rank[root_b]) rank[root_a]++;
}

int main(void) {
	if (scanf("%d %d", &N, &Q) != 2) return 0;
	temp_p[0] = 0;
	for (int i = 1; i < N; i++) {
		parent[i] = i;
		scanf("%d", &temp_p[i]);
		temp_p[i]--;
	}

	int last = N + Q - 1;
	for (int i = 0; i < last; i++) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 0) {
			scanf("%d", &b);
			temp_Q[i] = (Quest){ a, b-1, -1 };
		}
		else {
			scanf("%d %d", &b, &c);
			temp_Q[i] = (Quest){ a, b - 1, c - 1 };
		}
	}
	
	last--;
	for (int i = last; i >= 0; i--) {
		Quest curr = temp_Q[i];
		if (curr.q == 1) {
			if (Find(curr.n1) == Find(curr.n2)) {
				answer[index++] = 1;
			}
			else answer[index++] = 0;
		}
		else {
			Union(curr.n1, temp_p[curr.n1]);
		}
	}

	for (int i = Q - 1; i >= 0; i--) {
		if (answer[i] == 1) {
			printf("YES\n");
		}
		else printf("NO\n");
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
// int par[200005];
// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     int N, Q;
//     cin >> N >> Q;

//     for(int i=2; i<=N; i++){
//         int a;
//         cin >> a;
//         par[i]=a; // i번 정점의 부모를 a로 입력받음
//     }

//     vector<array<int, 3>> queries; // 쿼리들을 관리할 배열
//     for(int i=0; i<N-1+Q; i++){
//         int type;
//         cin >> type;
//         if(type==0){
//             int x;
//             cin >> x;
//             queries.push_back({type, x, -1}); // 0번 쿼리를 입력 받고
//         }
//         else{
//             int a, b;
//             cin >> a >> b;
//             queries.push_back({type, a, b}); // 1번 쿼리를 입력 받음
//         }
//     }

//     reverse(all(queries)); // 쿼리들의 순서를 모두 뒤집음
//     vector<string> ans; // 답을 받을 배열을 선언
//     UnionFind UF(N+1); // 각 정점이 같은 연결요소에 속해있는지를 확인하기 위한 UnionFind
//     for(auto [type, node1, node2] : queries){
//         if(type==0){
//             UF.Union(node1, par[node1]); // 분리연산을 거꾸로 처리하기 위해 UnionFind에서의 합연산을 수행
//         }
//         else{
//             if(UF.find(node1)==UF.find(node2)) ans.push_back("YES\n"); // 같은 연결요소라면 Yes를 출력
//             else ans.push_back("NO\n"); // 다른 연결요소라면 No를 출력
//         }
//     }

//     reverse(all(ans)); // 답의 순서와 원래 쿼리의 순서를 맞추기 위해서 뒤집어줌

//     for(auto s : ans) cout << s; // 답을 출력
// }