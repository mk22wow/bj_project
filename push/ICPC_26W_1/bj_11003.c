#include <stdio.h>

int N, L;
int list[5000000];
int result[5000000];

typedef struct{
    int data;
    int index;
}Pos;

Pos D[5000000];

int main(void){
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    int front = 0, rear = -1;
    for(int i=0; i<N; i++){
        while(rear>=front && D[rear].data>list[i]){
            rear--; 
        }
        D[++rear] = (Pos){list[i],i};
        while(front<rear && D[front].index<i-L+1){
            front++;
        }
        printf("%d ", D[front].data);
    }
    return 0;
}

// c++ 예시 코드
// #include <bits/stdc++.h>
// #define pii pair<int, int>
// #define all(v) v.begin(), v.end()

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N, L;
//     cin >> N >> L;
//     vector<int> V; // 입력 받는 수열
//     for(int i=0; i<N; i++){
//         int a;
//         cin >> a;
//         V.push_back(a);
//     }

//     deque<pii> dq; // 앞으로 구간의 최솟값이 될 가능성이 있는 원소들

//     for(int i=0; i<N; i++){
//         while(!dq.empty()&&dq.back().first>V[i]){
//             dq.pop_back();
//         } // 앞으로의 구간에서 최솟값이 될 수 없는 수들을 제거
//         dq.push_back({V[i], i});
//         while(!dq.empty()&&dq.front().second<=i-L){
//             dq.pop_front();
//         } // 앞으로의 구간 밖에 있게 될 수들을 제거
//         cout << dq.front().first << " ";
//     }
// }