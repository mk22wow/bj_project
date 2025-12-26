#include <stdio.h>
#include <stdlib.h>

int list[100][100];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

typedef struct{
    int y;
    int x;
}Position;

void Find(int list[100][100], int N, int M){
    Position* Q = (Position*)malloc(sizeof(Position)*N*M);
    int front = 0, tail = 0;
    Q[tail++] = (Position){0,0};
    Position temp;
    while(front<tail){
        temp = Q[front++];
        if(temp.y == N-1 && temp.x == M-1){
            break;
        }
        for(int i=0; i<4; i++){
            int temp_x = temp.x + dx[i];
            int temp_y = temp.y + dy[i];
            if(temp_x >= 0 && temp_x <M && temp_y >= 0 && temp_y <N && list[temp_y][temp_x] == 1){
                if(temp_x == 0 && temp_y == 0){
                    continue;
                }
                list[temp_y][temp_x] = list[temp.y][temp.x] + 1;
                Q[tail++] = (Position){temp_y, temp_x};
            }
        }
    }
    if(temp.y == N-1 && temp.x == M-1){
        printf("%d\n", list[N-1][M-1]);
    }
    else{
        printf("-1\n");
    }
    free(Q);
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    if(N<2 || N>100 || M<2 || M>100){
        return 0;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &list[i][j]);
        }
    }
    Find(list, N, M);
    return 0;
}