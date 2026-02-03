#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

typedef struct {
	int value;
	int index;
}Input;

Input Bar[MAX];
int	on[MAX];
int parent[MAX];
int rank[MAX] = { 0 };
int width[MAX];
long long answer;

int Compare(const void* a, const void* b) {
	Input* pa = (Input*)a;
	Input* pb = (Input*)b;
	return pb->value - pa->value;
}

int Find(int i){
    if(parent[i] == i) return i;
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
    width[root_a] += width[root_b];
    if(rank[root_a] == rank[root_b]){
        rank[root_a]++;
    }
}

int main(void) {
	while (1) {
		int n;
		answer = 0;
		scanf("%d", &n);
        if(n == 0) break;
		for (int i = 0; i < n; i++) {
			on[i] = 0;
			parent[i] = i;
            rank[i] = 0;
            width[i] = 1;
			int h;
			scanf("%d", &h);
			Bar[i] = (Input){ h, i };
		}
		qsort(Bar, n, sizeof(Input), Compare);

        for(int i=0; i<n; i++){
            int idx = Bar[i].index;
            on[idx] = 1;
            if(idx-1>=0 && on[idx-1] == 1){
                Union(idx, idx-1);
            } 
            if(idx+1<n && on[idx+1] == 1){
                Union(idx, idx+1);
            }

            long long size = (long long)Bar[i].value*(long long)width[Find(idx)];
            if(answer<size) answer = size;
        }

        printf("%lld\n", answer);
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
//     vector<int> setSz; // 헤당 원소를 루트로 하는 트리의 원소 개수를 관리하는 배열
//     public:
//     UnionFind(int N){
//         par.resize(N+1);
//         for(int i=0; i<=N; i++){
//             par[i]=i; // 부모가 없음 = 부모가 자기 자신
//             // 이렇게 함으로써 루트 노드를 찾을 때, 자기 자신이 부모인 정점을 찾아서 해당 정점의 부모를 출력하면 됨
//         }
//         rank.assign(N+1, 1);
//         setSz.assign(N+1, 1);
//     }
//     int find(int a){//a가 속한 트릐의 루트노드를 찾는 과정
//         return (par[a]==a) ? a : par[a] = find(par[a]); 
//         // 자신이 부모인 경우, 즉 트리의 루트인 경우 자기 자신을 그대로 반환
//         // 부모가 존재하는 경우, 부모에 find 연산을 적용
//         // 이후 반환값을 자신의 부모로 바꿈으로써 경로압축을 수행
//     }
//     int getSz(int a){
//         int x=find(a);
//         return setSz[x];
//     }
//     void Union(int a, int b){
//         int x=find(a);
//         int y=find(b); // 각 트리의 루트노드를 찾아줌
//         if(x==y) return;
//         if(rank[x]>rank[y]) swap(x, y);
//         par[x]=y; // x를 y의 자식으로 이어줌
//         setSz[y]+=setSz[x];// y를 루트로 하는 트리의 정점 개수로 갱신
//         if(rank[x]==rank[y]) rank[y]++;
//     }
// };

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     int N;
//     cin >> N; // 막대의 개수를 입력받음

//     vector<pii> V; // {막대의 크기, 막대의 위치}의 형식으로 입력을 받음
//     for(int i=0; i<N; i++){
//         int a;
//         cin >> a;
//         V.push_back({a, i});
//     }// 막대들을 입력받고

//     sort(V.rbegin(), V.rend()); // 막대들의 크기의 내림차순으로 입력을 받음

//     vector<int> isActivated(N+1);

//     UnionFind UF(N+1); // 연속된 최대 막대 집합의 크기를 관리하기 위한 UnionFind

//     int ans=0; // 현재까지 나온 최댓값

//     for(auto [h, i] : V){
//         isActivated[i]=1;
//         if(i-1>=0&&isActivated[i-1]) UF.Union(i-1, i);
//         if(i+1<N&&isActivated[i+1]) UF.Union(i, i+1);
//         int curSz=h*UF.getSz(i);
//         ans=max(ans, curSz);
//     }

//     cout << ans;
// }