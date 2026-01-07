#include <stdio.h>
#include <limits.h>
#include <string.h>

int N;
int list[10][10];
int visited[10][10];
int Min = INT_MAX;

int Find(int y, int x, int count){
    if(count == 1){    
        memset(visited, 0, sizeof(visited));
        visited[y][x] = 1;
        visited[y-1][x] = 1;
        visited[y+1][x] = 1;
        visited[y][x-1] = 1;
        visited[y][x+1] = 1;
        for(int i=1; i<N-1; i++){
            for(int j=1; j<N-1; j++){
                if(visited[i][j] == 0 && visited[i-1][j] == 0
                     && visited[i+1][j] == 0 && visited[i][j-1] == 0 && visited[i][j+1] == 0){  
                    Find(i,j,2);
                    visited[i][j] = 0;
                    visited[i-1][j] = 0;
                    visited[i+1][j] = 0;
                    visited[i][j-1] = 0;
                    visited[i][j+1] = 0;
                }
            }
        }
    }
    if(count == 2){
        visited[y][x] = 1;
        visited[y-1][x] = 1;
        visited[y+1][x] = 1;
        visited[y][x-1] = 1;
        visited[y][x+1] = 1;
        for(int i=1; i<N-1; i++){
            for(int j=1; j<N-1; j++){
                if(visited[i][j] == 0 && visited[i-1][j] == 0
                     && visited[i+1][j] == 0 && visited[i][j-1] == 0 && visited[i][j+1] == 0){
                    visited[i][j] = 1;
                    visited[i-1][j] = 1;
                    visited[i+1][j] = 1;
                    visited[i][j-1] = 1;
                    visited[i][j+1] = 1;
                    Find(i,j,3);
                    visited[i][j] = 0;
                    visited[i-1][j] = 0;
                    visited[i+1][j] = 0;
                    visited[i][j-1] = 0;
                    visited[i][j+1] = 0;  
                }
            }
        }
    }
    if(count == 3){
        int temp = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j] == 1){
                    temp+=list[i][j];
                }
            }
        }
        Min = Min<temp ? Min:temp;
    }
    return Min;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &list[i][j]);
        }
    }

    int result = INT_MAX;
    for(int i=1; i<N-1; i++){
        for(int j=1; j<N-1; j++){
            int temp = Find(i, j, 1);
            result = result<temp ? result:temp;
        }
    }

    printf("%d\n", result);
}