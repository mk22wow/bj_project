#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int list[101] = { 0 };
int Visited[101] = { 0 };
int count[101] = { 0 };
int S[10001];

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N+M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		list[a] = b;
	}

	int front = 0, rear = 0;
	count[1] = 0;
	S[rear++] = 1;
	
	while(front<rear) {
		int start_i = S[front++];
		if (start_i == 100) break;
		for (int j = start_i + 1; j <= start_i + 6; j++) {
			if (j <= 100)
			{
				int next_i = j;
				if (list[j] != 0) {
					next_i = list[j];
				}

				if (Visited[next_i] == 0) {
					count[next_i] = count[start_i] + 1;
					Visited[next_i] = 1;
					S[rear++] = next_i;
				}
			}
		}
	}

	printf("%d\n", count[100]);
	return 0;
}

// c++ 예시 코드
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, M; cin >> N >> M;
//     N += M;
//     vector<int> tele(110);
//     for (int i = 1; i < 110; i++) tele[i] = i;
//     while (N--) {
//         int u, v;
//         cin >> u >> v;
//         tele[u] = v;
//     }

//     vector<vector<int>> g(110);
//     for (int i = 1; i < 100; i++) {
//         for (int j = i + 1; j <= i + 6; j++) {
//             g[i].push_back(tele[j]);
//         }
//     }

//     queue<int> q;
//     q.push(1);
//     vector<int> dist(110, -1);
//     dist[1] = 0;
//     while (!q.empty()) {
//         int cur = q.front(); q.pop();
//         for (int nxt : g[cur]) {
//             if (dist[nxt] == -1) {
//                 dist[nxt] = dist[cur] + 1;
//                 q.push(nxt);
//             }
//         }
//     }

//     cout << dist[100];
//     return 0;
// }
