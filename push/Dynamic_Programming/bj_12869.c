#include <stdio.h>
#include <string.h>

int N;
int list[3] = {0};
int DP[61][61][61];
int Attack[6][3] = {{9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,3,9}, {1,9,3}};

typedef struct{
    int n1, n2, n3;
}State;
State Q[250000];

void Find(){
    DP[list[0]][list[1]][list[2]] = 0;
    int front = 0, rear = 0;
    Q[rear++] = (State){list[0],list[1],list[2]};
    while(front<rear){
        State curr = Q[front++];
        if(curr.n1 == 0 && curr.n2 == 0 && curr.n3 == 0){
            printf("%d\n", DP[0][0][0]);
            break;
        }
        for(int i=0; i<6; i++){
            int temp1 = curr.n1 - Attack[i][0];
            if(temp1<0) temp1 = 0;
            int temp2 = curr.n2 - Attack[i][1];
            if(temp2<0) temp2 = 0;
            int temp3 = curr.n3 - Attack[i][2];
            if(temp3<0) temp3 = 0;

            if(DP[temp1][temp2][temp3] == -1){
                DP[temp1][temp2][temp3] = DP[curr.n1][curr.n2][curr.n3]+1;
                Q[rear++] = (State){temp1, temp2, temp3};
            }
        }
    }
}

int main(void){
    scanf("%d", &N);
    memset(DP, -1, sizeof(DP));

    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    Find();
    return 0;
}