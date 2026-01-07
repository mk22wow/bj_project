#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000003

int list[1000][1000];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int front=0, rear=0;

typedef struct{
    int y;
    int x;
    int date;
}Position;

Position Q[MAX];

int BFS(int N, int M){
    int max = 0;
    while(front != rear){
        front = (front+1) % MAX;
        Position temp = Q[front];
        max = max>temp.date ? max:temp.date;
        for(int i=0; i<4; i++){
            int temp_y = temp.y + dy[i];
            int temp_x = temp.x + dx[i];

            if(temp_y<0 || temp_y>=N || temp_x<0 || temp_x>=M) continue;
            if(list[temp_y][temp_x]!=0) continue;
            if((rear+1)%MAX == front){
                printf("Need more");
            }
            list[temp_y][temp_x] = 1;
            rear = (rear+1)%MAX;
            Q[rear] = (Position){temp_y, temp_x, temp.date+1};
        }
    }
    return max;
}

int main(void){
    int M, N;
    scanf("%d %d", &M, &N);
    if(N<2 || N>1000 || M<2 || M>1000) return 0;
    //memset(list, 0, sizeof(list));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &list[i][j]);
            if(list[i][j] == 1){
                rear = (rear+1)%MAX;
                Q[rear] = (Position){i,j,0};
            }
        }
    }

    int result = BFS(N, M);

    int out = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(list[i][j] == 0){
                printf("-1\n");
                out = 1;
                break;
            }
        }
        if(out==1) break;
    }
    
    if(out != 1){
        printf("%d\n", result);
    }
    return 0;
}
