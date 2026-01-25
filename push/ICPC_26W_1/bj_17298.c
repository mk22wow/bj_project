#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 1000001

int N;
int list[MAX];
int S[MAX];
int result[MAX];

int main(void) {
	scanf("%d", &N);
	int top = -1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}

	for (int i = 0; i < N; i++) {
		while (top >= 0 && list[S[top]] < list[i]) {
			result[S[top]] = list[i];
			top--;
		}
		S[++top] = i;
	}

	for (int i = 0; i <= top; i++) {
		result[S[i]] = -1;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", result[i]);
	}
	return 0;
}

// c++ 예시 코드
// #include <bits/stdc++.h>
// #define pii pair<int, int>
// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N; // 수열의 원소 개수
//     cin >> N;

//     vector<int> V; // 입력받을 수열

//     for(int i=0; i<N; i++){
//         int a;
//         cin >> a;
//         V.push_back(a);
//     }

//     stack<int> st; // 아직까지 오큰수가 지정되지 않은 수들의 리스트(인덱스)
//     vector<int> ans(N); // 각 원소의 오큰수

//     for(int i=0; i<N; i++){ // 수들을 왼쪽부터 순회
//         while(!st.empty()&&V[st.top()]<V[i]){ // 스택의 탑이 현재 보고 있는 수보다 작으면
//             ans[st.top()]=V[i];
//             st.pop();
//         } // 스택의 탑의 오큰수를 현재 수로 지정해주고, 스택에서 제거
//         st.push(i); // 현재수를 오큰수가 지정되지 않은 수들의 리스트에 삽입
//     }

//     while(!st.empty()){ // 마지막까지 오큰수가 지정되지 않은 수들은
//         ans[st.top()]=-1;
//         st.pop();
//     }// 오큰수가 없는 것으로 간주

//     for(auto i : ans) cout << i << " ";
// }