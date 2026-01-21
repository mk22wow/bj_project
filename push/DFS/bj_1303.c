#include <stdio.h>

int N, M, count;
int Visited[101][101] = {0};
char war[101][101];
int result[2] = {0};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Find(int i, int j, char s){
    Visited[i][j] = 1;
    count++;
    for(int k=0; k<4; k++){
        int x = j + dx[k];
        int y = i + dy[k];
        if(x<0 || x>=N || y<0 || y>=M) continue;
        if(Visited[y][x] == 0 && war[y][x] == s){
            Find(y, x, s);
        }
    }
}

typedef struct{
    int y;
    int x;
}Pos;

Pos C[10000];
int BFS_V[100][100] = {0};
int BFS_Result[2] ={0};
void BFS(int i, int j){
    int front = 0, rear = 0;
    C[rear++] = (Pos){i, j};
    BFS_V[i][j] = 1;
    char s = war[i][j];
    while(front<rear){
        Pos curr = C[front++];
        for(int k=0; k<4; k++){
            int temp_x = curr.x+dx[k];
            int temp_y = curr.y+dy[k];
            if(temp_x<0 || temp_x>=N || temp_y<0 || temp_y>=M) continue;
            if(BFS_V[temp_y][temp_x] == 0 && war[temp_y][temp_x] == s){
                C[rear++] = (Pos){temp_y, temp_x};
                BFS_V[temp_y][temp_x] = 1;
            }
        }
    }
    if(s == 'W'){
        BFS_Result[0] += front*front;
    }
    else{
        BFS_Result[1] += front*front;
    }
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf(" %c", &war[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(Visited[i][j] == 0){
                count = 0;
                Find(i, j, war[i][j]);
                if(war[i][j] == 'W'){
                    result[0] += count*count;
                }
                else{
                    result[1] += count*count;
                }
            }
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(BFS_V[i][j] == 0){
                BFS(i, j);
            }
        }
    }

    printf("%d %d\n", result[0], result[1]);
    printf("%d %d\n", BFS_Result[0], BFS_Result[1]);
    return 0;
}