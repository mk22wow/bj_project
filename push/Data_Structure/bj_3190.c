#include <stdio.h>

int N, K, L;
int answer, direction = 0, tail_rear = 0;
int board[100][100] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct{
    int t;
    char c;
}Order;

Order list[100];

typedef struct{
    int x;
    int y;
}Tail;

Tail tail[10001];

int Hit(int x, int y){
    if(x<0 || x>=N || y<0 || y>=N) return 1;
    if(board[y][x] == 1) return 1;
    return 0;
}

void Find(){
    board[0][0] = 1;
    tail[tail_rear++] = (Tail){0,0};
    int order_cnt = 0, time = 0, tail_front = 0;
    int x = 0, y = 0;
    while(1){
        time++;
        x += dx[direction];
        y += dy[direction];

        if(Hit(x, y)) break;
        if(board[y][x] != 'a'){
            board[tail[tail_front%10001].y][tail[tail_front%10001].x] = 0;
            tail_front++;            
        }
        tail[tail_rear%10001] = (Tail){x, y};
        tail_rear++;
        board[y][x] = 1;
        
        if(order_cnt<L && time == list[order_cnt].t){
            if(list[order_cnt++].c == 'D'){
                direction = (direction+1)%4;
            }
            else direction = (direction+3)%4;
        }
    }

    answer = time;
    return;
}

int main(void){
    scanf("%d %d", &N, &K);
    for(int i=0; i<K; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        board[a-1][b-1] = 'a';
    }

    scanf("%d", &L);
    for(int i=0; i<L; i++){
        scanf("%d %c", &list[i].t, &list[i].c);
    }

    Find();
    printf("%d\n", answer);
    return 0;
}