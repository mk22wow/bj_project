#include <stdio.h>

int N;
int list[1000001];
int count[1000001];

typedef struct{
    int data;
    int index;
}Pos;

Pos S[1000001];
int result[1000001];

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
        count[list[i]]++;
    }

    int front = 0, rear = 0;
    for(int i=N-1; i>=0; i--){
        while(front<rear && count[list[i]]>=S[rear-1].data){
            rear--;   
        }

        if(front<rear) result[i] = list[S[rear-1].index];
        else result[i] = -1;

        S[rear++] = (Pos){count[list[i]], i};
    }

    for(int i=0; i<N; i++){
        printf("%d ", result[i]);
    }

    return 0;
}