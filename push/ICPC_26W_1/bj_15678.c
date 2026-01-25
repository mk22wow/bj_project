#include <stdio.h>
#include <limits.h>

typedef struct{
    long long sum;
    int index;
}Pos;

int N, D;
Pos Dp[100005];

int main(void){
    scanf("%d %d", &N, &D);
    
    int front = 0, rear = 0;
    long long Max = LLONG_MIN;
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);

        while(front<rear && Dp[front].index<i-D){
            front++;
        }

        long long curr;
        if(front<rear && Dp[front].sum>0){
            curr = Dp[front].sum;
        }
        else curr = 0;

        curr += temp;
        if(curr>Max) Max = curr;
        while(front<rear && Dp[rear-1].sum<curr){
            rear--;
        }
        Dp[rear++] = (Pos){curr, i};
    }

    printf("%lld\n", Max);
    return 0;
}