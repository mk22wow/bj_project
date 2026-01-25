#include <stdio.h>

typedef struct{
    int h;
    int c;
}Human;

int N;
Human S[500005];
long long count = 0;

int main(void){
    scanf("%d", &N);
    int top = -1;
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        
        Human current = {temp, 1};

        while(top>=0 && S[top].h < temp){
            count += S[top].c;
            top--;
        }

        if(top>=0 && S[top].h == temp){
            count += S[top].c;
            current.c = S[top].c+1;
            top--;

            if(top>=0) count++;
            S[++top] = current;
        }

        else{
            if(top>=0) count++;
            S[++top] = current;
        }
    }

    printf("%lld\n", count);
    return 0;
}
