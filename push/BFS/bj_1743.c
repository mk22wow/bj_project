#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int list[100][100];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

typedef struct{
    int y;
    int x;
}Position;

Position Q[101*101];

int BFS(int current_y, int current_x, int N, int M){
    int front = 0, rear = 0;
    list[current_y][current_x] = 0;
    Q[rear++] = (Position){current_y, current_x};
    while(front<rear){
        Position temp = Q[front++];
        for(int i=0; i<4; i++){
            int temp_y = temp.y + dy[i];
            int temp_x = temp.x + dx[i];
            if(temp_y>=0 && temp_y<N && temp_x>=0 &&temp_x<M && list[temp_y][temp_x] == 1){
                list[temp_y][temp_x] = 0;
                Q[rear++] = (Position){temp_y, temp_x};
            }
        }
    }
    return rear;
}

int main(void){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    if(N<1 || N>100 || M<1 || M>100 || K<1 || K>N*M) return 0;
    memset(list, 0, sizeof(int)*100*100);
    for(int i=0; i<K; i++){
        int r, c;
        scanf("%d %d", &r, &c);
        list[r-1][c-1] = 1;
    }
    int max = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(list[i][j] == 1){
                int area = BFS(i, j, N, M);
                max = max>area ? max: area;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
