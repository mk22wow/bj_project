#include <stdio.h>
#include <string.h>

int N, maxLen = 0, Idx = 0;
int list[1005] = {0};
int DP[1005] = {0};
int Pred[1005] = {0};
int ans[1005];

int main(void){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &list[i]);
        DP[i] = 1;
    }

    memset(Pred, 0, sizeof(Pred));

    for(int i=1; i<=N; i++){
        for(int j=1; j<i; j++){
            if(list[j]<list[i] && DP[i]<DP[j]+1){
                DP[i] = DP[j]+1;
                Pred[i] = j;
            }
        }

        if(maxLen<DP[i]){
            maxLen = DP[i];
            Idx = i;
        }
    }

    printf("%d\n", maxLen);
    for(int i=maxLen; i>=1; i--){
        ans[i] = list[Idx];
        Idx = Pred[Idx];
    }

    for(int i=1; i<=maxLen; i++){
        printf("%d ", ans[i]);
    }
    return 0;
}

// c++ 예시 코드
// #include <bits/stdc++.h>
// #define int long long
// #define pii pair<int, int>

// using namespace std;

// int DP[1005][1005]; // DP[현재 결정을 내릴 원소의 인덱스][마지막으로 넣은 원소의 인덱스]
// //= 해당 상태에서의 부분 수열의 최댓값
// pii backTrack[1005][1005]; //해당 상태의 최종 값에 영향을 미친 이전 상태

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N;
//     cin >> N; // 원소의 개수
//     vector<int> V(N+1);
//     for(int i=1; i<=N; i++){
//         cin >> V[i];
//     }

//     memset(DP, -1, sizeof(DP)); // 도달할 수 없는 상태는 모두 -1로 초기화
//     DP[1][0]=0; // 초기 상태(1번째 원소에 대해서 결정을 내려야 하고, 어떤 원소도 아직 고르지 않은 상태)
//     for(int i=1; i<=N; i++){ // 현재 부분 수열에 넣을지 말지를 결정할 원소의 인덱스
//         for(int j=0; j<=N; j++){ // 현재 부분 수열의 마지막 원소의 인덱스(없으면 0)
//             if(DP[i][j]<0) continue; // 현재 상태가 도달할 수 없는 경우, continue
//             // 1. 현재 원소를 부분수열의 뒤에 놓지 않음
//             // (i, j) -> (i+1, j)
//             if(DP[i+1][j]<DP[i][j]){
//                 backTrack[i+1][j]={i, j}; // 이전 상태를 저장
//                 DP[i+1][j]=DP[i][j]; // DP값을 갱신
//             }
//             // 2. 현재 원소를 부분수열의 뒤에 삽입
//             // (i, j) -> (i+1, i)
//             if(V[j]<V[i]&&DP[i+1][i]<DP[i][j]+1){
//                 backTrack[i+1][i]={i, j}; // 이전 상태를 저장
//                 DP[i+1][i]=DP[i][j]+1; // DP값을 갱신
//             }
//         } 
//     }
//     int length=0; // 지금까지 본 증가하는 부분 수열의 길이
//     pii curState; // 해당 길이를 갖게 되는 상태
//     for(int i=0; i<=N; i++){
//         if(length<DP[N+1][i]){
//             length=DP[N+1][i];
//             curState={N+1, i};
//         }
//     }
//     vector<int> ans; // 최장 증가 부분 수열을 담을 벡터
//     while(curState.first){
//         pii nxtState=backTrack[curState.first][curState.second]; // 역추적에서 다음으로 가게 될 상태
//         if(curState.second!=nxtState.second){ // 역추적하는 과정에서 마지막으로 넣은 원소가 바뀜
//             ans.push_back(V[curState.second]);
//         }
//         curState=nxtState; // 다음 상태로의 전이
//     }
//     reverse(ans.begin(), ans.end()); // 답의 순서를 맞춰줌
//     cout << ans.size() << "\n";
//     for(auto i : ans) cout << i << " ";
// }