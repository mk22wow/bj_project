#include <stdio.h>
#include <math.h>

int coin[8] = {
    0b111000000, 0b000111000, 0b000000111,
    0b100100100, 0b010010010, 0b001001001,
    0b100010001, 0b001010100
};

void BFS(int result[], int start){
    int Q[500];
    int front = 0, rear = 0;
    Q[rear++] = start;
    result[start] = 1;
    while(front<rear){
        int current = Q[front++];
        for(int i=0; i<8; i++){
            int temp = current ^ coin[i];
            if(result[temp] == 0){
                result[temp] = result[current] + 1;
                if(temp == 0 || temp == 511){
                    printf("%d\n", result[temp] - 1);
                    return;
                }   
                Q[rear++] = temp;
            }
        }
    }
    printf("-1\n");
}

int main(void){
    int N;
    scanf("%d", &N);
    while(N--){
        int start = 0;
        int result[512] = {0};
        for(int i=0; i<9; i++){
            char c;
            scanf(" %c", &c);
            if(c == 'H') start |= (1<<(8-i));
        }
        if(start == 0 || start == 511){
            printf("0\n");
        }
        else BFS(result, start);
    }

    return 0;
}