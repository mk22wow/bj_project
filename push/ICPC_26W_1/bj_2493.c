#include <stdio.h>

typedef struct{
    int h;
    int index;
}Tower;

int N;
int list[500005];
int result[500005] = {0};
Tower S[500005];

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    int top = -1;
    for(int i=0; i<N; i++){
        while(top>=0 && list[i]> S[top].h){
            top--;
        }

        if(top>=0) result[i] = S[top].index+1;
        else result[i] = 0;
        
        S[++top] = (Tower){list[i], i};
    }

    for(int i=0; i<N; i++){
        printf("%d ", result[i]);
    }
    return 0;
}