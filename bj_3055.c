#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int front = 0, rear = 0;
char list[MAX+1][MAX+1];

typedef struct{
    int y;
    int x;
    int count;
}Position;

Position Q[MAX*MAX];

int BFS(int R, int C){
    while(front<rear){
        Position temp = Q[front++];
        int move = 0;
        for(int i=0; i<4; i++){
            int temp_y = temp.y + dy[i];
            int temp_x = temp.x + dx[i];

            if(temp_y<0 || temp_y>=R || temp_x<0 || temp_x>=C) continue;
            if(list[temp_y][temp_x]=='.'){
                if(list[temp.y][temp.x] == 'S'){
                    list[temp_y][temp_x] = 'S';
                }
                if(list[temp.y][temp.x] == '*'){
                    list[temp_y][temp_x] = '*';
                }    
                Q[rear++] = (Position){temp_y, temp_x, temp.count+1};
            }
            
            if(list[temp_y][temp_x]=='D' && list[temp.y][temp.x]=='S'){
                return temp.count+1;
            }
            
        }
    }
    return 0;
}

int main(void){
    int R, C;
    scanf("%d %d", &R, &C);
    int dest_x, dest_y;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf(" %c", &list[i][j]);
            if(list[i][j] == '*'){
                Q[rear++] = (Position){i,j,0};
            }
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(list[i][j] == 'S'){
                Q[rear++] = (Position){i,j,0};
            }
        }
    }
    
    int result = BFS(R,C);
    if(result==0){
        printf("KAKTUS\n");
    }
    else printf("%d\n", result);

    return 0;
}
