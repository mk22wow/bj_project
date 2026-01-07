#include <stdio.h>
#include <limits.h>

int list[6][6];
int direction[3] = {0, -1, 1};

typedef struct{
    int data;
    int position;
    int dir;
    int level;
}Travel;
Travel Q[1000];

void FindMin(int N, int M){
    int front = 0, rear = 0;
    for(int i=0; i<M; i++){
        Q[rear++] = (Travel){list[0][i], i, -2, 1};
    }
    while(front<rear){
        Travel temp = Q[front++];
        if(temp.level < N){
            for(int i=0; i<3; i++){
                if(direction[i] != temp.dir){
                    int temp_position = temp.position + direction[i];
                    if(temp_position>=0 && temp_position<M){
                        Q[rear++] = (Travel){temp.data + list[temp.level][temp_position], temp_position, direction[i], temp.level+1};
                    }
                } 
            }
        }
    }
    int Min = Q[rear-1].data;
    while(1){
        rear--;
        if(Q[rear].level != N || rear<0){
            break;
        }
        Min = Min<Q[rear].data ? Min:Q[rear].data;
    }

    printf("%d\n", Min);
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    if(N<2 || N>6 || M<2 || M>6){
        return 0;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &list[i][j]);
        }
    }
    FindMin(N, M);

    return 0;
}