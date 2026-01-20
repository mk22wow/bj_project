#include <stdio.h>

int N, count = 0;
int home[16][16];
int dp[16][16][3] = {0};

// int dx[3] = {1, 1, 0};
// int dy[3] = {0, 1, 1};

// void Find(char c, int y, int x){
//     if(y == N-1 && x == N-1){
//         count++;
//         return;
//     }
//     if(c == 'a'){
//         for(int i=0; i<2; i++){
//             int pass = 1;
//             int current_y = y + dy[i];
//             int current_x = x + dx[i];
//             if(current_y>=N || current_x>=N) continue;
//             for(int j=x; j<=current_x; j++){
//                 for(int k=y; k<=current_y; k++){
//                     if(home[k][j]) pass = 0; 
//                 }
//             }
//             if(pass) Find('a'+i, current_y, current_x);
//         }
//     }
//     else if(c == 'b'){
//         for(int i=0; i<3; i++){
//             int pass = 1;
//             int current_y = y + dy[i];
//             int current_x = x + dx[i];
//             if(current_y>=N || current_x>=N) continue;
//             for(int j=x; j<=current_x; j++){
//                 for(int k=y; k<=current_y; k++){
//                     if(home[k][j]) pass = 0; 
//                 }
//             }
//             if(pass) Find('a'+i, current_y, current_x);
//         }
//     }
//     else{
//         for(int i=1; i<3; i++){
//             int pass = 1;
//             int current_y = y + dy[i];
//             int current_x = x + dx[i];
//             if(current_y>=N || current_x>=N) continue;
//             for(int j=x; j<=current_x; j++){
//                 for(int k=y; k<=current_y; k++){
//                     if(home[k][j]) pass = 0; 
//                 }
//             }
//             if(pass) Find('a'+i, current_y, current_x);
//         }
//     }
// }

// int main(void){
//     scanf("%d", &N);
//     for(int i=0; i<N; i++){
//         for(int j=0; j<N; j++){
//             scanf("%d", &home[i][j]);
//         }
//     }

//     Find('a', 0, 1);
//     printf("%d\n", count);
//     return 0;
// }

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &home[i][j]);
        }
    }

    dp[0][1][0] = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j+1<N && !home[i][j+1]){
                dp[i][j+1][0] += dp[i][j][0] + dp[i][j][2];
            }
            if(i+1<N && !home[i+1][j]){
                dp[i+1][j][1] += dp[i][j][1] + dp[i][j][2];
            }
            if(i+1<N && j+1<N && !home[i+1][j] && !home[i][j+1] && !home[i+1][j+1]){
                dp[i+1][j+1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            }
        }
    }
    printf("%d\n", dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2]);
    return 0;
}