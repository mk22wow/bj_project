#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int list[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

typedef struct{
    int y;
    int x;
}Position;

void Find(int M, int N, int** list, int y, int x){
    for(int i=0; i<4; i++){
        int temp_x = x + dx[i];
        int temp_y = y + dy[i];
        if(temp_x>=0 && temp_x<M && temp_y>=0 && temp_y<N){
            if(list[temp_y][temp_x] == 1){
                list[temp_y][temp_x] = 0;
                Find(M, N, list, temp_y, temp_x);
            }
        }
    }
    return;
}

void BFS(int M, int N, int i, int j){
    Position* Q = (Position*)malloc(sizeof(Position)* M*N);
    int front = 0, tail = 0;
    Q[tail++] = (Position){i, j};
    list[i][j] = 0;
    while(front<tail){
        Position temp = Q[front++];
        for(int i=0; i<4; i++){
            int temp_y = temp.y + dy[i];
            int temp_x = temp.x + dx[i];

            if(temp_x>=0 && temp_x<M && temp_y>=0 && temp_y<N && list[temp_y][temp_x] == 1){
                    list[temp_y][temp_x] = 0;
                    Q[tail++] = (Position){temp_y, temp_x};
            }
        } 
    }
    free(Q);
}

int main(void){
    int T, time = 0;
    scanf("%d", &T);
    while(time<T){
        int M, N, K;
        scanf("%d %d %d", &M, &N, &K);
        if(M<1 || M>50 || N<1 || N>50 || K<1 || K>2500){
            break;
        }
        // int** list = (int**)malloc(sizeof(int*)*N);
        // for(int i=0; i<N; i++){
        //     list[i] = (int*)calloc(M, sizeof(int));
        // }
        memset(list, 0, sizeof(list));
        for(int i=0; i<K; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            list[y][x] = 1;
        }
        int result = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(list[i][j] == 1){
                    // list[i][j] = 0;
                    // Find(M, N, list, i, j);
                    result++;
                    BFS(M, N, i, j);
                }
            }
        }
        printf("%d\n", result);
        // for(int i=0; i<N; i++){
        //     free(list[i]);
        // }
        // free(list);
        time++;
    }
}