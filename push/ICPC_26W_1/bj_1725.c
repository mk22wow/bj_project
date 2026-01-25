#include <stdio.h>
#include <limits.h>

#define MAX 100001

int N;
long long list[MAX];
long long left[MAX];
long long right[MAX];
long long index[MAX];
long long Max = LLONG_MIN;

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &list[i]);
	}
	int top = -1;
	for (int i = 0; i < N; i++) {
		while (top >= 0 && list[index[top]] > list[i]) {
			right[index[top--]] = i;
		}
		index[++top] = i;
	}

	for (int i = 0; i <= top; i++) {
		right[index[i]] = N;
	}

	top = -1;
	for (int i = N-1; i >= 0; i--) {
		while (top >= 0 && list[index[top]] > list[i]) {
			left[index[top--]] = i+1;
		}
		index[++top] = i;
	}

	for (int i = 0; i <= top; i++) {
		left[index[i]] = 0;
	}

	for (int i = 0; i < N; i++) {
		long long temp = (right[i] - left[i]) * list[i];
		if (temp > Max) Max = temp;
	}
	printf("%lld\n", Max);
	return 0;
}

// c++ 예시코드
// #include <bits/stdc++.h>
// #define pii pair<int, int>
// #define all(v) v.begin(), v.end()

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N;
//     cin >> N;
//     vector<int> V; // 입력되는 히스토그램
//     for(int i=0; i<N; i++){
//         int a;
//         cin >> a;
//         V.push_back(a);
//     }// 히스토그램을 입력 받음

//     vector<int> leftSmall(N), rightSmall(N);// 각각 왼작수와 오작수

//     stack<int> st; // 아직 왼/오작수가 정해지지 않은 수들(인덱스)

//     for(int i=0; i<N; i++){
//         while(!st.empty()&&V[st.top()]>V[i]){
//             rightSmall[st.top()]=i;
//             st.pop();
//         }
//         st.push(i);
//     }
//     while(!st.empty()){
//         rightSmall[st.top()]=-1;
//         st.pop();
//     }// 각 수들의 왼작수 인덱스를 모두 구함

//     for(int i=N-1; i>=0; i--){
//         while(!st.empty()&&V[st.top()]>V[i]){
//             leftSmall[st.top()]=i;
//             st.pop();
//         }
//         st.push(i);
//     }
//     while(!st.empty()){
//         leftSmall[st.top()]=-1;
//         st.pop();
//     }

//     int ansArea=0; // 답이 넓이
//     for(int i=0; i<N; i++){
//         int height=V[i];// 높이
//         int left=leftSmall[i]+1; // 왼쪽 끝점
//         int right=rightSmall[i]-1; // 오른쪽 끝점
//         if(rightSmall[i]<0) right=N-1;
//         int width=right-left+1; // 너비
//         int curArea=width*height; // 현재 막대의 전부를 포함하는 직사각형의 최대 넓이
//         ansArea=max(curArea, ansArea); // 답을 갱신
//     }

//     cout << ansArea;
// }