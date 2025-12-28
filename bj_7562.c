#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int list[300][300];
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

typedef struct{
    int y;
    int x;
    int count;
}Position;

Position Q[300*300];

void BFS(int I, int x_1, int y_1, int x_2, int y_2){
    int front = 0, rear = 0;
    Q[rear++] = (Position){y_1, x_1, 0};
    list[y_1][x_1] = 0;
    while(front<rear){
        Position temp = Q[front++];
        if(temp.y == y_2 && temp.x == x_2){
            printf("%d\n", temp.count);
            break;
        }
        for(int i=0; i<8; i++){
            int temp_y = temp.y + dy[i];
            int temp_x = temp.x + dx[i];
            if(temp_y>=0 && temp_y<I && temp_x>=0 && temp_x<I && list[temp_y][temp_x]==0){
                list[temp_y][temp_x] = 1;
                Q[rear++] = (Position){temp_y, temp_x, temp.count+1};
            }
        }
    }
}

int main(void){
    int T, time = 0;
    scanf("%d", &T);
    while(time<T){
        int I;
        scanf("%d", &I);
        memset(list, 0, sizeof(list));
        memset(Q, 0, sizeof(Q));
        int x_1, y_1, x_2, y_2;
        scanf("%d %d", &y_1, &x_1);
        scanf("%d %d", &y_2, &x_2);
        BFS(I, x_1, y_1, x_2, y_2);
        time++;
    }
    return 0;
}